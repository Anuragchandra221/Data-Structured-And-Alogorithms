#include <stdio.h>
int main(){
	int arr[10], n, s, i, flag=0;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	printf("Enter elements: ");
	for (i = 0; i < n; i++) {
	    scanf("%d", &arr[i]);
	}
    	printf("Enter the element to be searched: ");
  	scanf("%d", &s);
	for (i = 0; i < n; i++) {
	    if(arr[i]==s){
	        flag=1;
	        break;
	    }
	}
	if(flag==1){
	    printf("Element found");
	}else{
	    printf("Element not found");
	}
	return 0;
}