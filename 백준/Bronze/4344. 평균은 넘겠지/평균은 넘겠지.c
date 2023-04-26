int main()
{
	int score[1000], testcase, studentnum;
	int sum=0, count=0;
	float ave=0, ans[1000];
	int i, j;
	scanf("%d", &testcase);
	for (i=0; i < testcase; i++)
	{
		sum = 0;
		count = 0;
		scanf("%d", &studentnum);
		for (j=0; j < studentnum; j++)
		{
			scanf("%d", &score[j]);
			if (score[j] < 0 || score[j]>100)
			{
				return;
			}
		}
		for (j = 0; j < studentnum; j++)
		{
			sum += score[j];
		}
		ave = sum / studentnum;
		for (j = 0; j < studentnum; j++)
		{
			if (score[j] > ave)
				count++;
		}
		ans[i] = ((float)count / (float)studentnum)*100;
	}
	for (i = 0; i < testcase; i++) {
		printf("%.3f%\n", ans[i]);
	}
}