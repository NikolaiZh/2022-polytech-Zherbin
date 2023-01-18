#include <iostream>

int binary_search(int arr[], int l, int r, int x)
{
  while (r >= l)
   {
  int mid = l + (r-l) / 2;
 
  if (arr[mid] == x)
  {
  	return mid;
  }
  if (arr[mid] < x)
  {
        l = mid+1;
  } 
  else
  	{
  	r = mid-1;
 	 }
    }
    return -1;
  }
int main()
{
int arr[] = {2, 5, 6, 12, 17, 19, 25, 34, 37, 40};
int x = 34;
int n = sizeof(arr) / sizeof(arr[0]);
int result = binary_search(arr, 0, n-1, x);
if (result == -1)
{
std::cout << "Element is not present in array" << std::endl;
}
else
{
std::cout << "Id  " << result << std::endl;
} 
  return 0;
}
