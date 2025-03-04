#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int id;
	char title[100];
	char author[100];
} Book;
typedef struct {
	int id;
	char name[100];
	char phone[20];
} Member;
Member member[200];
Book book[200];
int bookcount = 0,membercount = 0;
void addbook() {
	printf("Enter Book ID: ");
	scanf("%d",&book[bookcount].id);
	getchar();
	printf("Enter Book Name: ");
	fgets(book[bookcount].title,100,stdin);
	book[bookcount].title[strcspn(book[bookcount].title,"\n")] = '\0';
	printf("Enter Book Author: ");
	fgets(book[bookcount].author,100,stdin);
	book[bookcount].author[strcspn(book[bookcount].author,"\n")] = '\0';
	bookcount++;
	printf("Book added succesfully!\n");
}
void readbook() {
	if(!bookcount) {
		printf("No books to display!\n");
	}
	else {
		printf("Book ID\t\tBook Title\t\tBook Author\n");
		for(int i = 0; i<bookcount; i++) {
			printf("%d\t\t%s\t\t%s\n",book[i].id,book[i].title,book[i].author);
		}

	}
}
void updatebook() {
	if(!bookcount) printf("No Books Available\n");
	else {
		int tempid,found = 0;
		printf("Enter id of Book which you want to update:\n");
		scanf("%d",&tempid);
		for(int i = 0; i<bookcount; i++) {
			if(tempid==book[i].id) {
				found = 1;
				int tempid2;
				char tempname[100],tempauthor[100];
				printf("Enter new ID: ");
				scanf("%d",&tempid2);
				getchar();
				book[i].id = tempid2;
				printf("Enter new title: ");
				fgets(tempname,100,stdin);
				tempname[strcspn(tempname,"\n")]='\0';
				strcpy(book[i].title,tempname);
				printf("Enter new author: ");
				fgets(tempauthor,100,stdin);
				tempauthor[strcspn(tempauthor,"\n")]='\0';
				strcpy(book[i].author,tempauthor);
				printf("Book Details updated successfully!!\n");
			}
		}
		if(!found) printf("Wrong ID provided\n");
	}

}
void deletebook() {
	if(!bookcount) printf("No books Available\n");
	else {
		int tempid,found = 0;
		printf("Enter id of the book you want to delete: ");
		scanf("%d",&tempid);
		for(int i = 0; i<bookcount; i++) {
			if(tempid==book[i].id) {
				found = 1;
				for(int j = i; j<bookcount-1; j++) {
					book[j]=book[j+1];
				}
				bookcount--;
				printf("Book deleted successfully!\n");
			}
		}
		if(!found) printf("Wrong ID provided\n");
	}

}
void addmember() {
	printf("Enter Member ID: ");
	scanf("%d",&member[membercount].id);
	getchar();
	printf("Enter Member's name: ");
	fgets(member[membercount].name,100,stdin);
	member[membercount].name[strcspn(member[membercount].name,"\n")] = '\0';
	printf("Enter Member's Phone number: ");
	fgets(member[membercount].phone,20,stdin);
	member[membercount].phone[strcspn(member[membercount].phone,"\n")] = '\0';
	printf("Member added succesfully\n");
	membercount++;
}

void readmember() {
	if(!membercount) printf("No members to display!\n");
	else {
		printf("Member ID\t\tMember Name\t\tMember phone no\n");
		for(int i = 0; i<membercount; i++) {
			printf("%d\t\t%s\t\t%s\n",member[i].id,member[i].name,member[i].phone);
		}
	}
}
void updatemember() {
	if(!membercount) printf("No Member's Available\n");
	else {
		int tempid,found = 0;
		printf("Enter id of member which you want to update: ");
		scanf("%d",&tempid);
		for(int i = 0; i<membercount; i++) {
			if(tempid==member[i].id) {
				found = 1;
				printf("Enter new ID: ");
				int tempid2;
				char tempname[100],tempphone[20];
				scanf("%d",&tempid2);
				member[i].id = tempid2;
				getchar();
				printf("Enter new name: ");
				fgets(tempname,100,stdin);
				tempname[strcspn(tempname,"\n")]='\0';
				strcpy(member[i].name,tempname);
				printf("Enter new phone: ");
				fgets(tempphone,20,stdin);
				tempphone[strcspn(tempphone,"\n")]='\0';
				strcpy(member[i].phone,tempphone);
				printf("Member Details updated succesfully!!\n");
			}
		}
		if(!found) printf("Wrong id\n");
	}
}
void deletemember() {
	if(!membercount) printf("No Member's Available\n");
	else {
		int tempid,found = 0;
		printf("Enter ID of the member you want to delete: ");
		scanf("%d",&tempid);
		for(int i = 0; i<membercount; i++) {
			if(tempid==member[i].id) {
				for(int j = i; j<membercount-1; j++) {
					member[j]=member[j+1];
					
				}
				found = 1;
				membercount--;
				printf("Member Deleted Succesfully\n");
			}
		}
		if(!found) printf("Wrong ID!\n");
	}

}
int main()
{
	int foundm=0,foundb=0,foundb1=0,n;
	int n1,n2;
	printf("Welcome to the library\n");
	while(1) {
		if(!foundm) {
			printf("1. Book Managing\n");
			printf("2. Member Managing\n");
			printf("3. Exit\n");
			printf("Enter Your Choice: ");
			scanf("%d",&n);
			foundm=1;
		}

		if(n==1) {
			if(!foundb) {
				printf("Book Managment\n");
				printf("1. Book Add\n");
				printf("2. Book Display\n");
				printf("3. Book Update\n");
				printf("4. Book Delete\n");
				printf("5. Back to Main Menu\n");
				foundb=1;
			}
			printf("Enter Your Choice: ");
			scanf("%d",&n1);
			switch(n1) {
			case 1:
				addbook();
				break;
			case 2:
				readbook();
				break;
			case 3:
				updatebook();
				break;
			case 4:
				deletebook();
				break;
			case 5:
			    foundb=0;
				foundm=0;
				break;
			default:
				printf("Invalid Input\n");
				break;
			}
		}

		else if(n==2) {
			if(!foundb1) {
				printf("Book Managment\n");
				printf("1. Member Add\n");
				printf("2. Member Display\n");
				printf("3. Member Update\n");
				printf("4. Member Delete\n");
				printf("5. Back to Main Menu\n");
				foundb1=1;
			}
			printf("Enter Your Choice: ");
			scanf("%d",&n2);
			switch(n2) {
			case 1:
				addmember();
				break;
			case 2:
				readmember();
				break;
			case 3:
				updatemember();
				break;
			case 4:
				deletemember();
				break;
			case 5:
			    foundb1=0;
				foundm=0;
				break;
			default:
				printf("Invalid Input\n");
				break;
			}
		}
		else if(n == 3){
		    printf("Exited Succesfully");
		    exit(0);
		} 
		else {
			printf("Invalid input\n");
		}
	}
}