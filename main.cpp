#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <chrono>

using namespace std;


void merge(int arr[], int temp[], int startA, int startB, int end)
{	
  
  int aptr = startA;
  int bptr = startB;
  int index = startA;
  
  while(aptr < startB && bptr <= end)
    if(arr[aptr] < arr[bptr])	
      temp[index++] = arr[aptr++];
    else
      temp[index++] = arr[bptr++];
    
  while(aptr < startB)
      temp[index++] = arr[aptr++];
  
  while(bptr <= end)
      temp[index++] = arr[bptr++];
  
  for(int i = startA; i <= end; i++)
      arr[i] = temp[i];
}


void mergeSort(int arr[], int temp[], int start, int end)
{	
  if(start < end)
  {	
    int mid = (start + end) / 2;
    mergeSort(arr, temp, start, mid);
    mergeSort(arr, temp, (mid + 1), end);
    merge(arr, temp, start, (mid + 1), end);
  }
}

//Partition function for my quick sort does the swaps and itterations for my quick sort.
int partition(int arr[], int start, int end)
{
  
  int pivot = arr[end];
  
  int loc = (start - 1);
  
  for(int i = start; i < end - 1; i++)
  {
    if(arr[i] <= pivot)
    {
      loc = loc + 1;
      int temp = arr[loc];
      arr[loc] = arr[i];
      arr[i] = temp;
    }
  }
  int temp = arr[loc + 1];
  arr[loc + 1] = arr[end];
  arr[end] = temp;
  return (loc + 1);
}


//Another type of sort that is faster to sort big arrays.
void quickSort(int arr[], int start, int end)
{	
  
  
  if(start >= end)
  {
    return;
  }
  else if(start < end)
  {
    int partIndex = partition(arr, start, end);
    
    quickSort(arr, start, partIndex - 1);
    quickSort(arr, partIndex + 1, end);
  }
}



int main()
{	
  srand(time(NULL));
  int input;
  do{
    
    cout << "Sort Menu " << endl;
    cout << "input 1 to test Quick sort. " << endl;
    cout << "input 2 to test Merge sort. " <<endl;
    cout << "input 3 to end program " << endl;
    cin >> input;
    
    if(input == 1)
    {	
      cout << "Quick Sort " << endl;
      
      int choice;
      do{
	
	cout << "Array Menu" << endl;
	cout << "input 1 for sorted arrays " << endl;
	cout << "input 2 for backwards arrays " << endl;
	cout << "input 3 for duplicate arrays " << endl;
	cout << "input 4 for random arrays " << endl;
	cout << "input 5 to select a different sort " << endl;
	cin >> choice;
	if(choice == 1)
	{	
	  int num;
	  int temp = 0;
	  cout << "input a size of the array: ";
	  cin >> num;
	  int *sortedArray = new int[num];
	  for(int i = 0; i < num; i++)
	  {	
	    sortedArray[i] = (i + 1);
	  }
	  
	  cout << "Sorted array" << endl;
	  auto start = std::chrono::system_clock::now();
	  quickSort(sortedArray, temp, num);
	  auto end = std::chrono::system_clock::now();
	  std::chrono::duration<double> elapsed_seconds = end-start;
	  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	  std::cout << "finished at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";
	  delete [] sortedArray;
	}
	else if(choice == 2)
	{	
	  int num;
	  int temp = 0;
	  cout << "input a size of the array: ";
	  cin >> num;
	  int *backwardsArray = new int[num];
	  for(int i = 0; i < num; i++)
	  {	
	    backwardsArray[i] = (num - (i + 1));
	  }
	  
	  cout << "Backwards array" << endl;
	  auto start = std::chrono::system_clock::now();
	  quickSort(backwardsArray, temp, num);
	  auto end = std::chrono::system_clock::now();
	  std::chrono::duration<double> elapsed_seconds = end-start;
	  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	  std::cout << "finished at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";
	  delete [] backwardsArray;
	}
	else if(choice == 3)
	{	
	  int num;
	  int temp = 0;
	  cout << "input a size of the array: ";
	  cin >> num;
	  int *duplicateArray = new int[num];
	  for(int i = 0; i < (num / 2); i++)
	  {	
	    duplicateArray[i] = (i + 1);
	  }
	  for(int i = (num / 2 ); i < num; i++)
	  {	
	    duplicateArray[i] = (num - (i + 1));
	  }
	  
	  cout << "Duplicated array" << endl;
	  auto start = std::chrono::system_clock::now();
	  quickSort(duplicateArray, temp, num);
	  auto end = std::chrono::system_clock::now();
	  std::chrono::duration<double> elapsed_seconds = end-start;
	  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	  std::cout << "finished at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";
	  delete [] duplicateArray;
	}
	else if(choice == 4)
	{	
	  int num;
	  int temp = 0;
	  cout << "input a size of the array: ";
	  cin >> num;
	  
	  int * Arr = new int[num];
	  
	  for(int i = 0; i < num; i++)
	  {	
	    Arr[i] = rand() % 100 + 1;
	  }	
	  
	  cout << "Random array" << endl;
	  auto start = std::chrono::system_clock::now();
	  quickSort(Arr, temp, num);
	  auto end = std::chrono::system_clock::now();
	  std::chrono::duration<double> elapsed_seconds = end-start;
	  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	  std::cout << "finished at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";
	  delete [] Arr;
	}
      }while(choice != 5);
    }
    else if(input == 2)
    {	
      cout << "Merge Sort " << endl;
      
      int choice;
      do{
	cout << endl;
	cout << "Array Menu" << endl;
	cout << "input 1 for sorted arrays " << endl;
	cout << "input 2 for backwards arrays " << endl;
	cout << "input 3 for duplicate arrays " << endl;
	cout << "input 4 for random arrays " << endl;
	cout << "input 5 to select a different sort " << endl;
	cin >> choice;
	if(choice == 1)
	{	
	  int num;
	  cout << "input a size of the array: ";
	  cin >> num;
	  int *sortedArray = new int[num];
	  int *tempArr = new int[num];
	  for(int i = 0; i < num; i++)
	  {	
	    sortedArray[i] = (i + 1);
	  }
	  
	  cout << "Sorted array" << endl;
	  auto start = std::chrono::system_clock::now();
	  mergeSort(sortedArray, tempArr, 0, (num - 1));
	  auto end = std::chrono::system_clock::now();
	  std::chrono::duration<double> elapsed_seconds = end-start;
	  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	  std::cout << "finished at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";
	  
	  delete [] tempArr;
	  delete [] sortedArray;
	}
	else if(choice == 2)
	{	
	  int num;
	  cout << "input a size of the array: ";
	  cin >> num;
	  int *backwardsArray = new int[num];
	  int *tempArr = new int[num];
	  for(int i = 0; i < num; i++)
	  {	
	    backwardsArray[i] = (num - (i + 1));
	  }
	  
	  cout << "Backwards array" << endl;
	  auto start = std::chrono::system_clock::now();
	  mergeSort(backwardsArray, tempArr, 0, (num - 1));
	  auto end = std::chrono::system_clock::now();
	  std::chrono::duration<double> elapsed_seconds = end-start;
	  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	  std::cout << "finished at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";
	  delete [] backwardsArray;
	  delete [] tempArr;
	}
	else if(choice == 3)
	{	
	  int num;
	  cout << "input a size of the array: ";
	  cin >> num;
	  int *duplicateArray = new int[num];
	  int *tempArr = new int[num];
	  for(int i = 0; i < (num / 2); i++)
	  {	
	    duplicateArray[i] = (i + 1);
	  }
	  for(int i = (num / 2 ); i < num; i++)
	  {	
	    duplicateArray[i] = (num - (i + 1));
	  }
	  
	  cout << "Duplicated array" << endl;
	  auto start = std::chrono::system_clock::now();
	  mergeSort(duplicateArray, tempArr, 0, (num - 1));
	  auto end = std::chrono::system_clock::now();
	  std::chrono::duration<double> elapsed_seconds = end-start;
	  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	  std::cout << "finished at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";
	  delete [] duplicateArray;
	  delete [] tempArr;
	}
	else if(choice == 4)
	{	
	  int num;
	  cout << "input a size of the array: ";
	  cin >> num;
	  
	  int *Arr = new int[num];
	  int *tempArr = new int[num];
	  for(int i = 0; i < num; i++)
	  {	
	    Arr[i] = rand() % 100 + 1;
	  }	
	  
	  cout << "Random array" << endl;
	  auto start = std::chrono::system_clock::now();
	  mergeSort(Arr, tempArr, 0, (num - 1));
	  auto end = std::chrono::system_clock::now();
	  std::chrono::duration<double> elapsed_seconds = end-start;
	  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	  std::cout << "finished at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";
	  delete [] Arr;
	  delete [] tempArr;
	}
      }while(choice != 5);
    }
    
  }while(input != 3);
  return 0;
}
