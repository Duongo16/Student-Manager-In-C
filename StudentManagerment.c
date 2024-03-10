#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student{
	char name[50];
	char id[20];
	char status[20];
	float ws;
	float ass;
	float pt;
	float pe;
	float fe;
	float total;
};

void delete_newline(char x[]);
void uppercase(char s[]);
void uppercase_first(char s[]);
void student_input(struct student *std, struct student lst[], int nos);
void student_output(struct student std);
void student_update(struct student *std);
void check_pass(struct student *std);
void input_list(struct student lst[], int *n, int *nos);
void output_list(struct student lst[], int nos);
void student_delete(struct student lst[], int *nos, char id[]);
void write_toFile(struct student lst[], int nos);
void read_fromFile(struct student lst[], int *nos);
int getInt();


int main() {
    struct student lst[100];
    int n = 0, c, nos = 0;
    char yn;
    int check = 1;

    while (check) {
        printf("\n-----------------MENU-----------------\n");
        printf("|   [1]. Open file.                  |\n");
        printf("|   [2]. Add students.               |\n");
        printf("|   [3]. Delete students.            |\n");
        printf("|   [4]. Print student list.         |\n");
        printf("|   [5]. Save file.                  |\n");
        printf("|   [6]. Exit.                       |\n");
        printf("-----------------****-----------------\n\n");
        
        c = getInt();

        switch (c) {
            case 1:
                read_fromFile(lst, &nos);
                if(nos<=0) {
                	printf("\n*** READ SUCCESSFULLY: EMPTY FILE ***\n");
				} else printf("\n*** READ SUCCESSFULLY: FILE HAS %d STUDENTS ***\n", nos);
                break;
            case 2:
                input_list(lst,&n,&nos);
                output_list(lst,nos);
                break;
            case 3: {
                printf("\nEnter the student ID you want to delete: ");
                char did[20];
                scanf("%s" , did);
                student_delete(lst, &nos, did);
                printf("\nStudent list after deleting: \n");
                output_list(lst,nos);
                break;
            }
            case 4:
                output_list(lst,nos);
                break;
            case 5:
                write_toFile(lst,nos);
                printf("\n*** ! WRITE SUCCESSFULLY ! ***\n");
                break;
            case 6:
                printf("\n---- !!! NOTE: YOU MUST SAVE TO SAVE INFORMATION !!! ----\n\n\n");
                printf("----------------   Do you want to exit?   ----------------\n\n");
	            printf("        [Y]. Exit                 [N]. I want to return.\n\n");
                printf("Enter your choice: ");
                scanf(" %c", &yn);
               	if(yn == 'Y') {
					check = 0;
					printf("\n\n*****************************************\n");
					printf("*                                       *\n");
					printf("* THANK YOU FOR USING DUONGO'S SERVICE! *\n");
					printf("*                                       *\n");
					printf("*****************************************\n");
				} else if(yn == 'N' ) {
					
				} else {
					printf("\n*** Invalid choice! Please choose a valid option. ***\n\n");
				}
		        break;
            default:
                printf("\n*** Invalid choice! Please choose a valid option. ***\n\n");
        }
    }
    return 0;
}

int getInt() {
    int value;
    char after;
    while (1) {
        printf("Enter your choice: ");
        if (scanf("%d%c", &value, &after) != 2 || after != '\n') {
            printf("\n*** Invalid input! Please enter a valid number. ***\n\n");
            while (getchar() != '\n'); 
        } else {
            return value;
        }
    }
}

void delete_newline(char x[]) {
	size_t len = strlen(x);
	if(len>0 && x[len-1] == '\n') { 
		x[len-1] = '\0';
	}
}
void uppercase(char s[]) {
	int i=0;
	while(s[i]!='\0' ) {
		if(s[i]<='z' && s[i]>='a') {
			s[i] -=32;
		}
		i++;
	}
}

void uppercase_first(char s[]) {
	int i = 0;
	while (s[i] != '\0') {
        if (i == 0 || s[i - 1] == ' ') {
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] -= 32;
            }
        } else {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 32;
            }
        }
        i++;
    }
}

void student_input(struct student *std, struct student lst[], int nos) {
	int i, existing_id;
	printf("\n- Enter name of student: ");
        fflush(stdin);
        fgets(std->name, sizeof(std->name), stdin);
        delete_newline(std->name);
        uppercase_first(std->name);

    do {
        existing_id = 0; 
        printf("- Enter ID of student: ");
        fflush(stdin);
        fgets(std->id, sizeof(std->id), stdin);
        delete_newline(std->id);

        for (i = 0; i < nos; i++) {
            if (strcmp(lst[i].id, std->id) == 0) {
                printf("\n*** Student ID already exists, please try again. ***\n\n");
                existing_id = 1;
                break;
            }
        }
    } while (existing_id);
    uppercase(std->id);

    do {
        printf("- Enter the Workshop score of student: ");
        if (scanf("%f", &std->ws) != 1 || std->ws <= 0 || std->ws > 10) {
            printf("\n*** Invalid input! Please enter a valid positive numeric value. ***\n\n");
            fflush(stdin);
        }
    } while (std->ws <= 0 || std->ws > 10);

    do {
        printf("- Enter the Assignment score of student: ");
        if (scanf("%f", &std->ass) != 1 || std->ass <= 0 || std->ass > 10) {
            printf("\n*** Invalid input! Please enter a valid positive numeric value. ***\n\n");
            fflush(stdin);
        }
    } while (std->ass <= 0 || std->ass > 10);

    do {
        printf("- Enter the Practice Test score of student: ");
        if (scanf("%f", &std->pt) != 1 || std->pt <= 0 || std->pt > 10) {
            printf("\n*** Invalid input! Please enter a valid positive numeric value. ***\n\n");
            fflush(stdin);
        }
    } while (std->pt <= 0 || std->pt > 10);

    do {
        printf("- Enter the Practice Exam score of student: ");
        if (scanf("%f", &std->pe) != 1 || std->pe <= 0 || std->pe > 10) {
            printf("\n*** Invalid input! Please enter a valid positive numeric value. ***\n\n");
            fflush(stdin);
        }
    } while (std->pe <= 0 || std->pe > 10) ;

    do {
        printf("- Enter the Final Exam score of student: ");
        if (scanf("%f", &std->fe) != 1 || std->fe <= 0 || std->fe > 10) {
            printf("\n*** Invalid input! Please enter a valid positive numeric value. ***\n\n");
            fflush(stdin);
        }
    } while (std->fe <= 0 || std->fe > 10);
    check_pass(std);
}

void student_output(struct student std) {
	printf("\n%20s \t %10s \t %6.1f \t %6.1f \t %6.1f \t %6.1f \t %6.1f \t %6.1f \t %6s", std.name,std.id,std.ws,std.ass,std.pt,std.pe,std.fe,std.total, std.status);
}

void check_pass(struct student *std) {
	std->total = 0.1*(std->ws + std->ass + std->pt) + 0.4*std->pe + 0.3*std->fe;
	if (std->ws>0 && std->ass>0 && std->pt>0 && std->pe>0 && std->fe>=4 && std->total>=5) {
		strcpy(std->status, "PASS");
	} else strcpy(std->status, "NOT PASS");
}


void input_list(struct student lst[], int *n, int *nos) {
    int i,j;
    char after;
    do {
        printf("Enter the number of students you want to add: ");
        if (scanf("%d%c", n, &after) != 2 || after != '\n' || *n < 0) {
            printf("\n*** Invalid input! Please enter a valid number. ***\n\n");
            fflush(stdin);  
        } else {
            break;  
        }
    } while (1);
	
    for (i = *nos; i < (*nos + *n); i++) {
        while(1) {
        	printf("\nEnter student %d: ", i + 1);
	        student_input(&lst[i], lst, *nos);; 
	        break;
		}
    }
    *nos+=*n;
}

void output_list(struct student lst[], int nos) {
	int i = 0;
	printf("%20s \t %10s \t %6s \t %6s \t %6s \t %6s \t %6s \t %6s \t %6s\n","Name", "ID", "Workshop", "Assignment", "PT", "PE", "FE","Average", "Status" );
	for(;i<nos;i++) {
		student_output(lst[i]);
		printf("\n");
	}
}


void student_delete(struct student lst[], int *nos, char id[]) {
	int i,j;
	for(i=0;i<*nos;i++) {
		if(strcmp(lst[i].id,id) == 0) {
			for(j=i;j<*nos-1;j++) {
				lst[j]=lst[j+1];
			}
			(*nos)--;
		}
	}
}

void write_toFile(struct student lst[], int nos) {
	int i;
	char file_name[100];
	do {
		printf("Enter the address or file name: ");
		fflush(stdin);
		fgets(file_name, sizeof(file_name), stdin);
		delete_newline(file_name);
		// Check if the file name ends with ".txt"
	    if (strlen(file_name) < 4 || strcmp(file_name + strlen(file_name) - 4, ".txt") != 0) {
	        printf("\nError: File name must end with .txt\n\n");
	        continue;
    	}
	} while(0);
	FILE*f;
	f = fopen(file_name, "w");
	if (f == NULL) {
    printf("Could not open file %s\n", file_name);
    return;
	}
	fseek(f, 0, SEEK_END);
    int file_size = ftell(f);
    if (file_size == 0) {
		fprintf(f, "%20s \t %10s \t %6s \t %6s \t %6s \t %6s \t %6s \t %6s \t %6s\n","Name", "ID", "Workshop", "Assignment", "PT", "PE", "FE","Average", "Status" );
	}
    if (file_size > 0) {
        fseek(f, -1, SEEK_END);
        if (fgetc(f) != '\n') {
            fprintf(f, "\0"); 
        }
    }
    for (i = 0; i < nos; i++) {
    	struct student std = lst[i];
    	check_pass(&std);
    	fprintf(f,"\n%20s \t %10s \t %6.1f \t %6.1f \t %6.1f \t %6.1f \t %6.1f \t %6.1f \t %6s", std.name,std.id,std.ws,std.ass,std.pt,std.pe,std.fe,std.total, std.status);
    }
    fclose(f);	
}
void read_fromFile(struct student lst[], int *nos) {
    int i = 0;
    char file_name[100];
    do {
		printf("Enter the address or file name: ");
		fflush(stdin);
		fgets(file_name, sizeof(file_name), stdin);
		delete_newline(file_name);
		// Check if the file name ends with ".txt"
	    if (strlen(file_name) < 4 || strcmp(file_name + strlen(file_name) - 4, ".txt") != 0) {
	        printf("\nError: File name must end with .txt\n\n");
	        continue;
    	}
	} while(0);
    FILE* f;
    f = fopen(file_name, "r");
    if (f == NULL) {
        printf("Could not open file  %s\n", file_name);
        return;
    }
    char header[256];
    fgets(header, sizeof(header), f); // Doc dong dau tien cua file
    while (fscanf(f, " %29[^\t] %9s %f %f %f %f %f %f %[^\n]\n",lst[i].name, lst[i].id, &lst[i].ws, &lst[i].ass,&lst[i].pt, &lst[i].pe, &lst[i].fe, &lst[i].total, lst[i].status) == 9) 
	{
        i++;
    }
    fclose(f);
    *nos = i;
}
