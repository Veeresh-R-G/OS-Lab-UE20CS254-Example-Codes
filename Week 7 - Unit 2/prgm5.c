//working with 2 mutex locks for threads
pthread_t tid1,tid2;
pthread_mutex_t first_mutex,second_mutex;

//thread one runs in this function
void *do_work_one(void *param)
{
pthread_mutex_lock(&first_mutex);
pthread_mutex_lock(&second_mutex);
printf("Enterin critical session\n");
sleep(5);
printf("exiting critical sesssion\n");
pthread_mutex_unlock(&first_mutex);
pthread_mutex_unlock(&second_mutex);
pthread_exit(0);
}


void *do_work_two(void *param)
{
pthread_mutex_lock(&first_mutex);
pthread_mutex_lock(&second_mutex);
printf("Enterin critical session\n");
sleep(5);
printf("exiting critical sesssion\n");
pthread_mutex_unlock(&second_mutex);
pthread_mutex_unlock(&first_mutex);
pthread_exit(0);
}
int main()
{
	pthread_create(&tid1,NULL,&do_work_one,NULL);
	pthread_create(&tid2,NULL,&do_work_two,NULL);
	
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_mutex_destroy(&first_mutex);
	pthread_mutex_destroy(&second_mutex);
	printf("hi");
	return 0;
	}