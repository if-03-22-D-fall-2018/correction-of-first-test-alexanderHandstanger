/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			grade_list.c
 * Author:			P. Bauer
 * Due Date:		November 18, 2010
 * ----------------------------------------------------------
 * Description:
 * Implementation of grade_list.h.
 * ----------------------------------------------------------
 */
#include "process_list.h"

#define MAX_LIST_ENTRIES 13

void init_process_list(ProcessList* pl){
// BAU: re-activated the next three lines.
for (size_t i = 0; i < MAX_LIST_ENTRIES; i++) { // BAU: changed from magic number 14 to MAX_LIST_ENTRIES
pl->processes[i] = 0;
}
pl->length = 0;
}

int get_length(const ProcessList* pl){
  // int counter = 0;
  // if(pl->processes[0] == 0){
  //   return 0;
  // }
  // for (size_t i = 0; i < 14; i++) {
  //   if(pl->processes[i] != 0){
  //     counter++;
  //   }
  // }
  // return counter;
  return pl->length;
}

bool add_entry(ProcessList* pl, struct ProcessListEntry* e){
  int counter = 0;
  for (size_t i = 0; i < MAX_LIST_ENTRIES; i++) {   // changed from magic number 14 to MAX_LIST_ENTRIES
    if(pl->processes[i] != 0){
      counter++;
      if(counter == 12){  //changed 13 to 12
        return false;
      }
    }
  }
  pl->processes[counter] = e;
  pl->length++;
  return true;

}

bool add_entries(ProcessList* pl, struct ProcessListEntry* e[], int n){
  int counter = 0;
  for (size_t i = 0; i < MAX_LIST_ENTRIES; i++) {   // changed from magic number 14 to MAX_LIST_ENTRIES
    if(pl->processes[i] != 0){
      counter++;
      if(counter == 12){    //changed 13 to 12
        pl->length = 13;
        return false;
      }
    }
  }
//lined out the following 4 lines

  // if(counter > n){
  //   pl->length = counter+1;
  //   return false;
  // }

  counter = pl->length; //adding this line
  for (int i = 0; i < n; i++) {  //changed size_t to int to remove a warning
    pl->processes[counter] = e[i];    //changed the index from processes from i to counter
    pl->length++;
    counter++; //adding this line
  }
  return true;
}

int get_process_with_id(const ProcessList* pl, int id, struct ProcessListEntry* result_list[]){
  int counter = 0;
  //re-activated the next 6 lines
  for (int i = 0; i < pl->length; i++) { // changed from magic number 14 to pl->lenght        //changed size_t to int to remove a warning
    if(pl->processes[i]->pid == id){
      counter++;
      result_list[0] = pl->processes[i]; //changed the index from result_list from i to 0
      return counter; //adding this line
    }
  }

  return counter;
}

int get_processes_with_state(const ProcessList* pl, enum ProcessState state, struct ProcessListEntry* result_list[]){
  int counter = 0;
  //re-activated the next 5 lines
  for (int i = 0; i < pl->length; i++) {   // changed from magic number 14 to pl->lenght          //changed size_t to int to remove a warning
    if(pl->processes[i]->state == state){
      result_list[counter] = pl->processes[i];    // adding current process in the for, to save the result_list         //changed the index from result_list from i to counter
      counter++;
    }
  }
  return counter;
}

struct ProcessListEntry* get_process_with_highest_cpu_consumption(const ProcessList* pl){
  //line out all statemants with index (3)
  //line out all statemants with pointer_r (2)
  struct ProcessListEntry* x;
  x = pl->processes[0];
  //re-activated the following 9 lines and then I lined out(see above)
  //struct ProcessListEntry* pointer_r = &pl->processes[0];
  // int index;
  for (int i = 0; i < pl->length; i++) {   // changed from magic number 14 to pl->length    //changed size_t to int to remove a warning
    if(pl->processes[i]->cpu_usage > x->cpu_usage){   //changed the if statement
      //index = i;
      x = pl->processes[i]; //adding this line
    }
  }
  //pointer_r = pl->processes[index];
  //return pointer_r;

  return x;
}

struct ProcessListEntry* get_process_with_lowest_cpu_consumption(const ProcessList* pl){
  //line out all statemants with pointer_r (3)
  //lined out 2 ifs after the first for (with body(index = 13;))
  //lined out row 146(index = i+1)
  //lined out row 138 + 139 to remove warnings
  struct ProcessListEntry* x;
  x = pl->processes[0];

  //re-activated the following 9 lines and the I lined out(see above)
  //struct ProcessListEntry* pointer_r;
  //int temp = 0;
  //int index;
  for (int i = 0; i < pl->length; i++) { // changed from magic number 14 to pl->length    //changed size_t to int to remove a warning
    //if(i+1 >= 13){
      //if(pl->processes[13]->cpu_usage < pl->processes[index]->cpu_usage){
        //index = 13;
      //}
    //}
    if(pl->processes[i]->cpu_usage < x->cpu_usage){   //changed the if statement
      //index = i+1;
      x = pl->processes[i]; // adding this line
    }
  }
  //pointer_r = pl->processes[index];
  //return pointer_r;

  return x;
}

int get_top_n_processes_cpu(const ProcessList* pl, int n, struct ProcessListEntry* result_list[]){
  int counter = 0;
  // for (size_t i = 0; i < 14; i++) {
  //   if(pl->processes[i] != 0){
  //     counter++;
  //   }
  // }
  // if(n > counter){
  //   return MAX_LIST_ENTRIES;
  // }
  return counter; //changed return statement to remove a warning
}

int get_bottom_n_processes_cpu(const ProcessList* pl, int n, struct ProcessListEntry *result_list[]){
  int counter = 0;
  // for (size_t i = 0; i < 14; i++) {
  //   if(pl->processes[i] != 0){
  //     counter++;
  //   }
  // }
  // if(n > counter){
  //   return MAX_LIST_ENTRIES;
  // }
  return counter; //changed return statemante to remove a warning
}
