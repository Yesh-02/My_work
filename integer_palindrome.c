4
	int input,i=0,j=0,array[]={0};
	scanf("%d",&input);
	while(input>=10)
	{
		array[i]=input%10;
		input=(int)input/10;
		printf("i=%d,j=%d,array[i]=%d,array[j]=%d\n",i,j,array[i],array[j]);
		i++;
	}
	array[i]=input;
	j=0;
	i=sizeof(array)/sizeof(array[0])-1;
	while(i>=j)
	{
		if(array[i]==array[j])
		{
			printf("i=%d,j=%d\n",i,j);
			i--;
			j++;
			printf("i=%d,j=%d\n",i,j);
		}
		else
		{
			printf("no\n");
			printf("array[i]=%d,array[j]=%d\n",array[i],array[j]);
			goto exit;
		}
	}
	printf("yes\n");
	exit:
	printf("inside exit\n");
	return 0;
}
	
		