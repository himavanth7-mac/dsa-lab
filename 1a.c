#include <stdio.h>

int main()
{
   int arr[100];
   int n, i;
   int max;
   int element, position;

  // Read array
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  printf("Enter %d elements:\n", n);
  for(i = 0; i < n; i++)
  {
     scanf("%d", &arr[i]);
  }

  // (a) Print the array
  printf("\n(a) Array Elements:\n");
  for(i = 0; i < n; i++)
  {
      printf("%d ", arr[i]);
  }

  // (b) Find the largest element
  max = arr[0];

  for(i = 1; i < n; i++)
  {
     if(arr[i] > max)
     {
            max = arr[i];
        }
    }

    printf("\n\n(b) Largest Element = %d\n", max);

    // (c) Insert an element
    printf("\nEnter the element to insert: ");
    scanf("%d", &element);

    printf("Enter the position (1 to %d): ", n + 1);
    scanf("%d", &position);

    for(i = n; i >= position; i--)
    {
       arr[i] = arr[i - 1];
    }

    arr[position - 1] = element;
    n++;

    printf("\n(c) Array after insertion:\n");
    for(i = 0; i < n; i++)
    {
       printf("%d ", arr[i]);
    }

    return 0;
}
