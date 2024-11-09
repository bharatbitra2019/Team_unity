#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OUTCOMES 100
#define FILENAME "course_outcome.txt"

typedef struct {
    char cour_out_code[20];
    char cour_id[20];
    char bloom_id[20];
    float e_proficiency;
    float e_attainment;
} CourseOutcome;

CourseOutcome outcomes[MAX_OUTCOMES];
int outcome_count = 0;


void Team_unity_create() {
    if (outcome_count >= MAX_OUTCOMES) {
        printf("Cannot add more outcomes. Maximum limit reached.\n");
        return;
    }
    
    CourseOutcome new_outcome;
    
    printf("Enter Course Outcome Code: ");
    scanf("%s", new_outcome.cour_out_code);
    printf("Enter Course ID: ");
    scanf("%s", new_outcome.cour_id);
    printf("Enter Bloom ID: ");
    scanf("%s", new_outcome.bloom_id);
    printf("Enter Proficiency Level: ");
    scanf("%f", &new_outcome.e_proficiency);
    printf("Enter Attainment Level: ");
    scanf("%f", &new_outcome.e_attainment);
    
    
    
    outcomes[outcome_count++] = new_outcome;

    FILE *file = fopen(FILENAME, "a");
    if (file) {
        fprintf(file, "%s,%s,%s,%.2f,%.2f\n", new_outcome.cour_out_code, new_outcome.cour_id, new_outcome.bloom_id, new_outcome.e_proficiency, new_outcome.e_attainment);
        fclose(file);
    } else {
        printf("Error opening file for writing.\n");
    }
    
    printf("Course Outcome created successfully.\n");
            return;
}


void Team_unity_update() {
    char cour_out_code[20];
    printf("Enter Course Outcome Code to update: ");
    scanf("%s", cour_out_code);
    
    for (int i = 0; i < outcome_count; i++) {
        if (strcmp(outcomes[i].cour_out_code, cour_out_code) == 0) {
            printf("Updating Course Outcome:\n");
            printf("Enter New Course ID: ");
            scanf("%s", outcomes[i].cour_id);
            printf("Enter New Bloom ID: ");
            scanf("%s", outcomes[i].bloom_id);
            printf("Enter New Proficiency Level: ");
            scanf("%f", &outcomes[i].e_proficiency);
            printf("Enter New Attainment Level: ");
            scanf("%f", &outcomes[i].e_attainment);
            printf("Course Outcome updated successfully.\n");
            return;
        }
    }
    printf("Course Outcome with code %s not found.\n", cour_out_code);
}

void Team_unity_retrieve() {
    printf("Retrieving Course Outcomes:\n");
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-20s | %-20s | %-12s | %-12s |\n", "Outcome Code", "Course ID", "Bloom ID", "Proficiency", "Attainment");
    printf("----------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < outcome_count; i++) {
        printf("| %-20s | %-20s | %-20s | %-12.2f | %-12.2f |\n",
               outcomes[i].cour_out_code, outcomes[i].cour_id, outcomes[i].bloom_id, outcomes[i].e_proficiency, outcomes[i].e_attainment);
    }
    printf("----------------------------------------------------------------------------------------------------\n");
}

void Team_unity_delete() {
    char cour_out_code[20];
    printf("Enter Course Outcome Code to delete: ");
    scanf("%s", cour_out_code);
    
    for (int i = 0; i < outcome_count; i++) {
        if (strcmp(outcomes[i].cour_out_code, cour_out_code) == 0) {
            for (int j = i; j < outcome_count - 1; j++) {
                outcomes[j] = outcomes[j + 1]; // Shift elements left
            }
            outcome_count--;
            printf("Course Outcome deleted successfully.\n");
            return;
        }
    }
    printf("Course Outcome with code %s not found.\n", cour_out_code);
}

void Team_unity_storing() {
    FILE *file = fopen(FILENAME, "w"); // Open the file in write mode
    if (file) {
        for (int i = 0; i < outcome_count; i++) {
            fprintf(file, "%s,%s,%s,%.2f,%.2f\n", 
                    outcomes[i].cour_out_code, 
                    outcomes[i].cour_id, 
                    outcomes[i].bloom_id, 
                    outcomes[i].e_proficiency, 
                    outcomes[i].e_attainment);
        }
        fclose(file); 
        printf("Outcomes stored successfully.\n");
    } else {
        printf("Error opening file for writing.\n");
    }
}

void display_outcomes() {
    printf("--------------------------------------------------------------------------\n");
    printf("| %-15s | %-10s | %-10s | %-12s | %-12s |\n", 
           "Outcome Code", "Course ID", "Bloom ID", "Proficiency", "Attainment");
    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < outcome_count; i++) {
        printf("| %-15s | %-10s | %-10s | %-12.2f | %-12.2f |\n",
               outcomes[i].cour_out_code, outcomes[i].cour_id, outcomes[i].bloom_id, 
               outcomes[i].e_proficiency, outcomes[i].e_attainment);
    }

    printf("--------------------------------------------------------------------------\n");
}


void Team_unity_bubble_sort() {
    for (int i = 0; i < outcome_count - 1; i++) {
        for (int j = 0; j < outcome_count - i - 1; j++) {
            if (strcmp(outcomes[j].cour_out_code, outcomes[j + 1].cour_out_code) > 0) {
                CourseOutcome temp = outcomes[j];
                outcomes[j] = outcomes[j + 1];
                outcomes[j + 1] = temp;
            }
        }
    }
    printf("Outcomes sorted using Bubble Sort.\n");
}


int Team_unity_partition(CourseOutcome arr[], int low, int high) {
    CourseOutcome pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (strcmp(arr[j].cour_out_code, pivot.cour_out_code) < 0) {
            i++;
            CourseOutcome temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    CourseOutcome temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void Team_unity_quick_sort(CourseOutcome arr[], int low, int high) {
    if (low < high) {
        int pi = Team_unity_partition(arr, low, high);
        Team_unity_quick_sort(arr, low, pi - 1);
        Team_unity_quick_sort(arr, pi + 1, high);
    }
}


void Team_unity_Compare_sorting_bubble() {
    Team_unity_bubble_sort();
    display_outcomes();
}


void Team_unity_Compare_sorting_quick() {
    Team_unity_quick_sort(outcomes, 0, outcome_count - 1);
    display_outcomes();
}

int Team_unity_linear_search(char *cour_out_code) {
    for (int i = 0; i < outcome_count; i++) {
        if (strcmp(outcomes[i].cour_out_code, cour_out_code) == 0) {
            return i;
        }
    }
    return -1;
}

int Team_unity_binary_search(char *cour_out_code, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (strcmp(outcomes[mid].cour_out_code, cour_out_code) == 0) {
            return mid;
        }
        if (strcmp(outcomes[mid].cour_out_code, cour_out_code) < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
void Team_unity_Compare_Search_linear(char *cour_out_code) {
    int index = Team_unity_linear_search(cour_out_code);
    if (index != -1) {
        printf("Course Outcome found using Linear Search:\n");
        printf("--------------------------------------------------------------------------\n");
        printf("| %-15s | %-10s | %-10s | %-12s | %-12s |\n", 
               "Outcome Code", "Course ID", "Bloom ID", "Proficiency", "Attainment");
        printf("--------------------------------------------------------------------------\n");
        printf("| %-15s | %-10s | %-10s | %-12.2f | %-12.2f |\n",
               outcomes[index].cour_out_code, outcomes[index].cour_id, 
               outcomes[index].bloom_id, outcomes[index].e_proficiency, 
               outcomes[index].e_attainment);
        printf("--------------------------------------------------------------------------\n");
    } else {
        printf("Course Outcome with code %s not found.\n", cour_out_code);
    }
}
void Team_unity_Compare_Search_binary(char *cour_out_code) {
    Team_unity_quick_sort(outcomes, 0, outcome_count - 1); 
    int index = Team_unity_binary_search(cour_out_code, 0, outcome_count - 1);
    if (index != -1) {
        printf("Course Outcome found using Binary Search:\n");
        printf("---------------------------------------------------------------------------\n");
        printf("| %-15s | %-10s | %-10s | %-12s | %-12s |\n", 
               "Outcome Code", "Course ID", "Bloom ID", "Proficiency", "Attainment");
        printf("---------------------------------------------------------------------------\n");
        printf("| %-15s | %-10s | %-10s | %-12.2f | %-12.2f |\n",
               outcomes[index].cour_out_code, outcomes[index].cour_id, 
               outcomes[index].bloom_id, outcomes[index].e_proficiency, 
               outcomes[index].e_attainment);
        printf("---------------------------------------------------------------------------\n");
    } else {
        printf("Course Outcome with code %s not found.\n", cour_out_code);
    }
}
void Team_unity_complexity_Search() {
    printf("Time Complexity for Linear Search: O(n)\n");
    printf("Time Complexity for Binary Search: O(log n)\n");
}

void Team_unity_complexity_sorting() {
    printf("Time Complexity for Bubble Sort: O(n^2)\n");
    printf("Time Complexity for Quick Sort: O(n log n)\n");
}

void Team_unity_Search_algorithm_details() {
    printf("Linear Search Algorithm:\n");
    printf("1. Start from the first element and compare it with the target.\n");
    printf("2. If it matches, return the index.\n");
    printf("3. If not, move to the next element and repeat.\n");
    printf("4. If the end of the list is reached, return -1.\n\n");

    printf("Binary Search Algorithm:\n");
    printf("1. Ensure the array is sorted.\n");
    printf("2. Set low and high pointers.\n");
    printf("3. Calculate the mid index.\n");
    printf("4. If the mid element matches the target, return the index.\n");
    printf("5. If the target is less than the mid element, search the left half.\n");
    printf("6. If the target is greater, search the right half.\n");
    printf("7. Repeat until the target is found or the range is invalid.\n");
}

void Team_unity_sort_algorithm_details() {
    printf("Bubble Sort Algorithm:\n");
    printf("1. Compare adjacent elements and swap them if they are in the wrong order.\n");
    printf("2. Repeat the process for each element in the array.\n");
    printf("3. Continue until no swaps are needed, indicating the array is sorted.\n\n");

    printf("Quick Sort Algorithm:\n");
    printf("1. Choose a pivot element from the array.\n");
 printf("2. Partition the array into two halves: elements less than the pivot and elements greater than the pivot.\n");
    printf("3. Recursively apply the same process to the left and right halves.\n");
    printf("4. Combine the sorted halves to get the final sorted array.\n");
}

int main() {
    int choice;
    char cour_out_code[20];
    while (1) {
        printf("\nCourse Outcome Management System\n");
        printf("1. Create Course Outcome\n");
        printf("2. Update Course Outcome\n");
        printf("3. Retrieve Course Outcomes\n");
        printf("4. Delete Course Outcome\n");
        printf("5. Sort Outcomes (Bubble Sort)\n");
        printf("6. Sort Outcomes (Quick Sort)\n");
        printf("7. Search Outcome (Linear Search)\n");
        printf("8. Search Outcome (Binary Search)\n");
        printf("9. Show Time Complexity (Searching)\n");
        printf("10. Show Time Complexity (Sorting)\n");
        printf("11. Show Search Algorithm Details\n");
        printf("12. Show Sort Algorithm Details\n");
        printf("13. Store Outcomes\n");
        printf("14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                Team_unity_create();
                break;
            case 2:
                Team_unity_update();
                break;
            case 3:
                Team_unity_retrieve();
                break;
            case 4:
                Team_unity_delete();
                break;
            case 5:
                printf("Enter Course Outcome Code to sort: ");
                scanf("%s", cour_out_code);
                Team_unity_Compare_sorting_bubble();
                break;
            case 6:
                printf("Enter Course Outcome Code to sort: ");
                scanf("%s", cour_out_code);
                Team_unity_Compare_sorting_quick();
                break;
            case 7: 
                printf("Enter Course Outcome Code to search: ");
                scanf("%s", cour_out_code);
                Team_unity_Compare_Search_linear(cour_out_code);
                break;
            
            case 8:
                printf("Enter Course Outcome Code to search: ");
                scanf("%s", cour_out_code);
                Team_unity_Compare_Search_binary(cour_out_code);
                break;
            case 9:
                Team_unity_complexity_Search();
                break;
            case 10:
                Team_unity_complexity_sorting();
                break;
            case 11:
                Team_unity_Search_algorithm_details();
                break;
            case 12:
                Team_unity_sort_algorithm_details();
                break;
            case 13:
                Team_unity_storing();
                break;
            case 14:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}