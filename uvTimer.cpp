#include <stdio.h>
#include "uv.h"

uv_loop_t *loop;
uv_timer_t gc_req;
uv_timer_t fake_job_req;

void gc(uv_timer_t *handle) {
	fprintf(stderr, "Freeing unused objects\n");
}

void fake_job(uv_timer_t *handle) {
	fprintf(stdout, "Fake job done\n");
}

int main() 
{
	loop = uv_default_loop();

	uv_timer_init(loop, &gc_req);                           // 初始化定时器 gc_req
	//uv_unref((uv_handle_t*) &gc_req);                       // 如果没有其他任务，则释放 gc_req 定时任务

	uv_timer_start(&gc_req, gc, 1000, 2000);                   // 启动 gc_req 定时器, 0 毫秒开始，每 2000 毫秒执行一次

	uv_timer_init(loop, &fake_job_req);                     // 初始化定时器 fake_job_req
	uv_timer_start(&fake_job_req, fake_job, 9000, 0);       // 启动 fake_job_req 定时器, 9000 毫秒后开始执行, 不需要循环执行
	uv_run(loop, UV_RUN_DEFAULT);      
	return 0;
}
