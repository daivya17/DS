void moveZeroes(int* nums, int numsSize) {
    int a=0;
    for(int i=0;i<numsSize;i++){
        if (nums[i]!=0){
            nums[a]=nums[i];
            a++;
        }
        }
    for(int i=a;i<numsSize;i++){
        nums[i]=0;
    }
}
