#include <iostream>
#include <graphics.h>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

// Initialize the size with the total numbers to sorted
// and the gap to be maintained in graph
vector<int> numbers;
int size = 200;
int gap = 4;


// Function for swapping the lines graphically
void swap(int i, int j, int x, int y)
{
	// Swapping the first line with the correct line
	// by making it black again and then draw the pixel
	// for white color.
	//setlinestyle(1, 0, 3);
	setcolor(GREEN); //green
	line(i, size, i, size - x);
	setcolor(BLACK); // black
	line(i, size, i, size - x);
	setcolor(YELLOW); //yellow
	line(i, size, i, size - y);
	
	//delay(2);
	// Swapping the first line with the correct line
	// by making it black again and then draw the pixel
	// for white color.
	
	setcolor(BLACK); //green
	line(j, size, j, size - y);
	setcolor(GREEN); // black
	line(j, size, j, size - y);
	setcolor(GREEN); //green
	line(j, size, j, size - x);
}

// Bubble sort function
void bubbleSort()
{
	int temp, i, j;

	for (i = 1; i < size; i++)
	{
		for (j = 0; j < size - i; j++)
		{
			if (numbers[j] > numbers[j + 1])
			{
				temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;

				// As we swapped the last two numbers
				// just swap the lines with the values.
				// This is function call
				// for swapping the lines
				
				swap(gap * j + 1, gap * (j + 1) + 1, numbers[j + 1], numbers[j]);
			}
		}
	}
}

// Selection sort function
void selectionSort()
{
	
	int min, i, j, temp;
	
    	for (i = 0; i < size; i++)
    	{
        	min = i;
        
        	for (j = i + 1; j < size; j++)
        	{
            		if (numbers[j] < numbers[min])
            		{
                		temp = numbers[min];
                		numbers[min] = numbers[j];
                		numbers[j] = temp;
                
                		swap(gap * min + 1, gap * j + 1, numbers[j], numbers[min]);
            		}
        	}
    	}
}

// Insertion sort function
void insertionSort()
{
	
	int i, j, temp;
	
    	for (i = 1; i < size; i++)
    	{
        	temp = numbers[i];
        	j = i - 1;

        	// Move elements of arr[0..i-1], 
        	// that are greater than key, to one
        	// position ahead of their
        	// current position
        	while (j >= 0 && numbers[j] > temp)
        	{
            		numbers[j + 1] = numbers[j];
            		swap(gap * j + 1, gap * (temp) + 1, numbers[temp], numbers[j]);
            		j = j - 1;
        	}
        	numbers[j + 1] = temp;
    	}
}

// Function to shuffle the array
void disrupt()
{	
	random_shuffle(numbers.begin(), numbers.end());
	cleardevice();
	setcolor(YELLOW);
	for (int i = 1; i <= gap * size; i += gap)
	{
		line(i, size, i, (size - numbers[i / gap]));
		//rectangle(i, (size - numbers[i / gap]), (i+gap), size);
	}
}


// Driver program
int main()
{
	int ch=-1, ans;

	// auto detection of screen size
	int gd = DETECT, gm;
	int wid1;

	//initgraph(&gd, &gm, NULL);
	
	// Graph initialization
	// setting up window size (gap*size) * (size)
	wid1 = initwindow(gap * size + 1, size + 1);
	setcurrentwindow(wid1);

	// Initializing the array
	for (int i = size; i>=0 ; i--)
		numbers.push_back(i);
	
/*	int temp;
   	for(int i=size;i>=0;i--)
   	{
      		temp=rand()%100;
      		numbers.push_back(temp);
  	}*/

	
	// Find a seed and shuffle the array
	// to make it random.
	// Here different type of array
	// can be taken to results
	// such as nearly sorted, already sorted,
	// reverse sorted to visualize the result
	//unsigned seed = chrono::system_clock::now().time_since_epoch().count();

	random_shuffle(numbers.begin(), numbers.end());

	// Initial plot of numbers in graph taking
	// the vector position as x-axis and its
	// corresponding value will be the height of line.
	for (int i = 1; i <= gap * size; i += gap)
	{
		line(i, size, i, (size - numbers[i / gap]));
		//rectangle(i, (size - numbers[i / gap]), (i+gap), size);
	}
	
	
	// Delay the code
	//delay(200);
	
	
	while(ch!=NULL)
	{
		system("cls");
		cout << "\n\n***** MENU *****\n\n1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Shuffle\n5. Exit\n\nEnter your choice: ";
        cin >> ch;
        
        	switch(ch)
        	{
        	case 1:
        		bubbleSort();
        		break;
        	
        	case 2:
        		selectionSort();
        		break;
        	
        	case 3:
        		insertionSort();
        		break;
        	
			case 4:
				disrupt();
				break;
        	
        	case 5:
        		cout<<"\nDATA USED:\n";
        		for (int i = 0; i < size; i++)
				{
					cout << numbers[i] << " ";
				}
				
				cout << "\n\nProcess exited after great time with return value \"THANK YOU\"\n\n\n\n\n";
				ans=-1;

				break;

				// Close the graph
				closegraph();	
			}
		if(ans == -1)
		{
			break;
		}
		
		/*cout << "\nDo you want to continue? (y/n) ";
        	cin >> ans;*/
        
	}


	return 0;
}
