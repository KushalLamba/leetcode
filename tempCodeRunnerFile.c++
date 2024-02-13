  int index = -1;
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]<arr[i+1])
        {
            index=i;
            break;
        }
    }
    if(index==-1)
    {
        sort(arr,arr+n);
    }
    else{
    for(int i=n-2;i>index;i--)
    {
        if(arr[i]>arr[index])
        {
            swap(arr[i],arr[index]);
            sort(arr+index+1,arr+n);
        }
    }
    }