#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


typedef struct {
	int day;
	int month;
	int year;
}Date;


typedef struct {
	int bookId;
	char title[50];
	char author[50];
	int publishYear;
	int quantity;
}Book;

typedef struct {
	int Id;
	int bookId;
	int status;
    char borrowerName[50];
    Date borrowDate;
    Date returnDate;
}Borrow;


Borrow borrows[MAX];
int totalBooks = 35; 
int nextBooksId = 35; 
int booksPerPage = 10;
int totalBorrow = 0; 
int nextBooksBorrow = 0;
	

void addNewBooks(); 
int isValidNum( char str[] );
int titleBooksExisted (char title[]);
int checkInteger( char c[] );
int titleBooksExistedUpdate (int bookId, char title[]);
void updateInformationBooks();
int idBooksExisted ( int booksId );
void disPlaysInformationOldBooks( int booksId );
void disPlaysBooksInPage(); 
void deleteInformationById ();
void searchBook ();
void addBooksBorrow();
int isValidDate( int day , int month , int year );
void returnBooks();
void disPlayBookBorrow();


Book books[MAX] = {
    {1, "To Kill a Mockingbird", "Harper Lee", 1960, 1},
    {2, "1984", "George Orwell", 1949, 8},
    {3, "The Great Gatsby", "F. Scott Fitzgerald", 1925, 7},
    {4, "The Catcher in the Rye", "J.D. Salinger", 1951, 4},
    {5, "The Lord of the Rings", "J.R.R. Tolkien", 1954, 9},
    {6, "Harry Potter", "J.K. Rowling", 1997, 12},
    {7, "The Hobbit", "J.R.R. Tolkien", 1937, 10},
    {8, "The Da Vinci Code", "Dan Brown", 2003, 6},
    {9, "The Alchemist", "Paulo Coelho", 1988, 15},
    {10, "The Little Prince", "Saint-Exupery", 1943, 8},
    {11, "The Chronicles of Narnia", "C.S. Lewis", 1950, 7},
    {12, "Brave New World", "Aldous Huxley", 1932, 5},
    {13, "The Hunger Games", "Suzanne Collins", 2008, 11},
    {14, "The Kite Runner", "Khaled Hosseini", 2003, 6},
    {15, "The Book Thief", "Markus Zusak", 2005, 4},
    {16, "Gone with the Wind", "Margaret Mitchell", 1936, 3},
    {17, "The Shining", "Stephen King", 1977, 8},
    {18, "The Fault in Our Stars", "John Green", 2012, 9},
    {19, "The Girl on the Train", "Paula Hawkins", 2015, 7},
    {20, "The Help", "Kathryn Stockett", 2009, 5},
    {21, "Life of Pi", "Yann Martel", 2001, 6},
    {22, "One Hundred Years", "Gabriel", 1967, 7},
    {23, "The Secret History", "Donna Tartt", 1992, 4},
    {24, "The Goldfinch", "Donna Tartt", 2013, 5},
    {25, "The Night Circus", "Erin Morgenstern", 2011, 6},
    {26, "A Game of Thrones", "George R.R. Martin", 1996, 8},
    {27, "The Handmaid's Tale", "Margaret Atwood", 1985, 7},
    {28, "Dune", "Frank Herbert", 1965, 6},
    {29, "The Martian", "Andy Weir", 2011, 9},
    {30, "Ready Player One", "Ernest Cline", 2011, 8},
    {31, "The Girl", "Stieg Larsson", 2005, 7},
    {32, "The Silent Patient", "Alex Michaelides", 2019, 10},
    {33, "Where the Crawdads Sing", "Delia Owens", 2018, 11},
    {34, "Educated", "Tara Westover", 2018, 6},
    {35, "Becoming", "Michelle Obama", 2018, 9}
};



int main(){
	
	int choose;
	
	do {
	system("cls");
	printf("\n============================MENU============================");
	printf("\n||1.Them moi sach.                                        ||");
	printf("\n||2.Cap nhat thong tin sach.                              ||");
	printf("\n||3.Hien thi danh sach (co phan trang).                   ||");
	printf("\n||4.Xoa thong tin sach.                                   ||");
	printf("\n||5.Tim kiem sach (tim kiem doi tuong ).                  ||");
	printf("\n||6.Them moi phieu muon.                                  ||");
	printf("\n||7.Tra sach.                                             ||");
	printf("\n||8.Hien thi danh sach phieu muon(co phan trang).         ||");
	printf("\n||9.Thoat.                                                ||"); 
	printf("\n============================================================");
	printf("\nChon chuc nang : ");
	scanf("%d" , &choose );
	getchar();
	
	switch ( choose ){
		case 1:
			system("cls");
			addNewBooks(); 
			printf("\nNhap thu bat ki de tro ve menu.");
        	getchar(); 
		 break;
		case 2:
			system("cls");
			updateInformationBooks(); 
			printf("\nNhap thu bat ki de tro ve menu.");
        	getchar();  
		 break;
		case 3:
			system("cls");
			disPlaysBooksInPage ();
			printf("\nNhap thu bat ki de tro ve menu.");
        	getchar();  
		 break;
		case 4:
			system("cls");
			deleteInformationById ();
			printf("\nNhap thu bat ki de tro ve menu.");
        	getchar(); 
		 break;
		case 5:
			system("cls");
			searchBook ();
			printf("\nNhap thu bat ki de tro ve menu.");
        	getchar(); 
		 break;
		case 6:
			system("cls");
			addBooksBorrow();
			printf("\nNhap thu bat ki de tro ve menu.");
        	getchar(); 
		 break;
		case 7:
			system("cls");
			returnBooks();
			printf("\nNhap thu bat ki de tro ve menu.");
        	getchar(); 
		 break;
		case 8:
			system("cls");
			disPlayBookBorrow();
			printf("\nNhap thu bat ki de tro ve menu.");
        	getchar(); 
		 break;
		case 9:
			printf("\nCam on ban da su dung chuong trinh nay. See You Again."); 
		 break; 
		default:
		    system("cls");
			printf("Loi - Xin moi ban cho tu 1 - 9.\n");
			printf("\nNhap thu bat ki de tro ve menu.");
        	getchar(); 
		 break; 
	} 
	
    }while ( choose != 9 ); 
	
	return 0;
}

void addNewBooks (){
	
	if( totalBooks >= MAX ){
		printf("So luong sach da day khong the them.");
		return; 
	} 
	
	printf("\n==========Enter Information New Books==========\n");
	
	    printf("\n---Book %d---\n" , totalBooks + 1 );
     
         
		books[totalBooks].bookId = ++nextBooksId; 
		printf("Book ID %d \n" , books[totalBooks].bookId ); 

		do {
			printf("Nhap tieu de cua sach : ");
			fgets( books[totalBooks].title , 50 , stdin );
			books[totalBooks].title[strcspn(books[totalBooks].title , "\n")] = '\0'; 
			
			if ( strlen(books[totalBooks].title) == 0 ||  strcasecmp(books[totalBooks].title , " ") == 0 ){
				printf("Tieu de khong duoc de trong \n"); 
			} else if ( titleBooksExisted ( books[totalBooks].title ) == 0  ){
				printf("Tieu de sach bi trung lap ! Vui long nhap title khac \n"); 
			} 
			
		}while( titleBooksExisted ( books[totalBooks].title ) == 0   || strlen(books[totalBooks].title) == 0  ||  strcasecmp(books[totalBooks].title , " ") == 0 ); 
		
		char yearString[10];
		do {
		     
		     printf("Nhap nam san xuat :");
		     fgets ( yearString , 10 , stdin );
		     yearString[strcspn(yearString , "\n")] = '\0';
		     
		     if ( strlen ( yearString) == 0 || strcasecmp( yearString , " ") == 0 ){
		     	printf("Nam san xuat khong duoc de trong.\n");
		     	continue;
			 } else if ( !isValidNum(yearString) ){
				printf("Nam san xuat phai nhap so nguyen duong.\n");
				continue; 
			} else {
				books[totalBooks].publishYear = atoi( yearString); 
			}  
			
            if (books[totalBooks].publishYear < 1900) {
                printf("Nam san xuat phai lon hon hoac bang 1900.\n");
            } else if (books[totalBooks].publishYear > 2025 ) {
                printf("Nam san xuat khong the lon hon nam hien tai 2025.\n");
            }
		
		} while ( strlen ( yearString ) == 0 || 
		          strcasecmp ( yearString , " ") == 0 || 
				  !isValidNum ( yearString ) || 
				  books[totalBooks].publishYear < 1900 || 
				  books[totalBooks].publishYear > 2025  );
		
		do {
			printf("Nhap ten tac gia : ");
			fgets(books[totalBooks].author , 50 , stdin );
			books[totalBooks].author[strcspn(books[totalBooks].author , "\n")] = '\0'; 
			
			if ( strlen (books[totalBooks].author) == 0 ){
				printf("Khong duoc de trong ten tac gia"); 
			} 
			
		} while (strlen(books[totalBooks].author) == 0 );
		
		char quantityString[10]; 
		do {
			
			printf("Nhap so luong : ");
		    fgets ( quantityString , 10 , stdin );
			quantityString[strcspn( quantityString , "\n")] = '\0';
			
			if ( strlen(quantityString) == 0 || strcasecmp(quantityString , " ") == 0 ){
				printf("So luong sach trong kho khong duoc de trong.\n");
			    continue; 
			} else if ( !isValidNum(quantityString) ){
				printf("So luong sach phai nhap so nguyen duong.\n"); 
				continue; 
			} else {
			    books[totalBooks].quantity = atoi(quantityString); 
			} 
			
			if( books[totalBooks].quantity < 0 ){
				printf("So luong sach phai lon hon hoac bang 0.\n"); 
			} 
			
		} while (  books[totalBooks].quantity < 0 || 
		           !isValidNum(quantityString) || 
				   strlen(quantityString) == 0 || 
				   strcasecmp(quantityString , " ") == 0 ); 
		
	totalBooks ++;
	printf("\nDa them sach thanh cong.\n"); 
	
}


int titleBooksExisted (char title[]){
	for ( int i = 0 ;  i < totalBooks ; i++){
		if ( strcasecmp ( books[i].title , title ) == 0){
			return 0; 
		} 
	} 
	return 1; 
} 



int isValidNum( char str[] ){
	
	int start = 0;
    if(str[0] == '-' || str[0] == '+') {
        start = 1; 
    } 
    
    if(start == 1 && strlen(str) == 1) {
        return 0;
    }
    
	for ( int i = start ; str[i] != '\0' ; i++ ){
		if ( str[i] < '0' || str[i] >'9'){
			return 0;
		}
	}
	
	return 1;
}  


int checkInteger( char c[] ){
	
	int i = 0 ; 
	
	if  ( c[0] == '+' || c[0] == '-'){
		i = 1;
		if ( c[1] == '\0' ){
			return 0;
		} 
	}
	
	for (  i = 0 ; c[i] != '\0' ; i++ ){
		if ( c[i] < '0' || c[i] > '9'){
			return 0;
		}
	}
	return 1;
}  


int idBooksExisted ( int booksId ){
	
	for ( int i = 0 ; i < totalBooks ; i++ ){
		if ( books[i].bookId == booksId  ){
			return 0; 
		} 
	} 
	return 1; 
} 



void updateInformationBooks (){
	
	if ( totalBooks == 0 ){
		printf("Danh sach rong - Khong co danh sach nao de update\n");
		return; 
	} 
	
	int booksId; 
	char idString[10];
	
	do {
		
		printf("\n---Nhap ID de update---\n"); 
		printf("\nNhap ID : ");
		fgets (idString , 10  , stdin );
		idString[strcspn(idString , "\n")] = '\0';
		
		if ( strlen (idString) == 0 || strcasecmp (idString , " ") == 0 ){
			printf("\nID khong duoc de trong - Xin vui long nhap ID."); 
			continue;
		} else if ( !isValidNum( idString )){
			printf("\nID phai la so nguyen duong.");
			continue;
		} else {
			booksId = atoi(idString);
		}
		
		if ( booksId < 0 ){
			printf("\nID phai lon hon 0.");
			continue;
		} else if ( idBooksExisted ( booksId ) == 1 ){
			printf("\nID nay khong ton tai - Vui long nhap lai ID.");
		}
		
	} while( strlen( idString ) == 0 || 
	         strcasecmp (idString , " ") == 0 ||
			 !isValidNum ( idString ) || 
			 booksId < 0 || 
			 idBooksExisted ( booksId ) == 1 ); 
	
	char title[50];
	disPlaysInformationOldBooks(booksId);

	for ( int i = 0 ; i < totalBooks ; i++){
		if ( books[i].bookId == booksId ){
			
			printf("\n----------ENTER UPDATE BOOK INFORMATION----------\n"); 
			do {
				printf("Nhap tieu de : ");
				fgets(title , 50 , stdin );
				title[strcspn(title , "\n")] = '\0'; 
				
				if ( strlen ( title ) == 0 || strcasecmp(title , " ") == 0 ){
					printf("Title khong duoc de trong.\n"); 
				} else if ( titleBooksExistedUpdate ( booksId, title ) == 0  ){
					printf("Title sach da trung ! Xin vui long nhap lai title.\n"); 
				} 
				
			} while (strlen(title) == 0 || 
			         strcasecmp (title , " ") == 0 || 
					 titleBooksExistedUpdate ( booksId , title ) == 0 ); 
					 
	strcpy(books[i].title, title) ;
			
			
	char yearString[10];
		do {
		     
		     printf("Nhap nam san xuat : ");
		     fgets ( yearString , 10 , stdin );
		     yearString[strcspn(yearString , "\n")] = '\0';
		     
		     if ( strlen ( yearString) == 0 || strcasecmp( yearString , " ") == 0 ){
		     	printf("Nam san xuat khong duoc de trong.\n");
		     	continue;
			 } else if ( !isValidNum (yearString) ){
				printf("Nam san xuat phai nhap so nguyen duong.\n ");
				continue; 
			} else {
				books[i].publishYear = atoi( yearString); 
			} 
			
			if ( books[i].publishYear < 1900 ){
				printf("Nam san xuat lon hon 1900.\n");
			} else if ( books[i].publishYear > 2025 ){
				printf("Nam san xuat be hon 2025.\n"); 
			} 
		
    	} while ( strlen ( yearString ) == 0 || 
		          strcasecmp ( yearString , " ") == 0 || 
				  !isValidNum ( yearString ) || 
				  books[i].publishYear > 2025 || 
				  books[i].publishYear < 1900 );
				  
		    do {
		    	printf("Nhap tac gia : ");
			    fgets(books[i].author , 50 , stdin );
		    	books[i].author[strcspn(books[i].author , "\n")] = '\0'; 
		    	if ( strlen (books[i].author) == 0 || strcasecmp(books[i].author , " ") == 0 ){
			    	printf("\nKhong duoc de trong ten tac gia"); 
		    	} 
	    	} while (strlen(books[i].author) == 0 || strcasecmp (books[i].author , " ") == 0 );
	    	
	    	
	char quantityString[10]; 
	    	do {
			
		        printf("Nhap so luong : ");
	    	    fgets ( quantityString , 10 , stdin );
		    	quantityString[strcspn( quantityString , "\n")] = '\0';
			
		    	if ( strlen(quantityString) == 0 || strcasecmp(quantityString , " ") == 0 ){
		    		printf("So luong sach trong kho khong duoc de trong.\n");
		    	    continue; 
		    	} else if ( !isValidNum(quantityString) ){
		    		printf("So luong sach phai nhap so nguyen.\n"); 
		    		continue; 
		    	} else {
		    	    books[i].quantity = atoi(quantityString); 
		    	} 
			
		    	if( books[i].quantity < 0 ){
		    		printf("So luong sach phai lon hon hoac bang 0.\n"); 
		    	} 
			
	    	} while (  books[i].quantity < 0 || 
	       	           !isValidNum(quantityString) || 
			    	   strlen(quantityString) == 0 || 
			    	   strcasecmp(quantityString , " ") == 0 ); 
	    
		} 
	} 
	
	printf("Ban da update thanh cong.\n"); 
} 


int titleBooksExistedUpdate (int booksId, char title[]){
	for ( int i = 0 ;  i < totalBooks ; i++){
		if ( strcasecmp ( books[i].title , title ) == 0 && books[i].bookId != booksId ){
			return 0; 
		} 
	} 
	return 1; 
} 


void disPlaysInformationOldBooks ( int booksId ){
	for ( int i = 0 ; i < totalBooks ; i++){
		if ( books[i].bookId == booksId ){ 
	        printf("\n============== INFORMATION ABOUT OLD BOOK  =================\n");
            printf("+-----------------------------------------------------------+\n");
            printf("| %-30s: %-25d |\n", "Book ID", books[i].bookId);
            printf("| %-30s: %-25s |\n", "Title", books[i].title);
            printf("| %-30s: %-25d |\n", "Publish Year", books[i].publishYear);
            printf("| %-30s: %-25s |\n", "Author", books[i].author);
            printf("| %-30s: %-25d |\n", "Quantity", books[i].quantity);
            printf("+-----------------------------------------------------------+\n");
            
            return;  
        }
    }
          printf("Khong tim thay sach co ID : %d\n" , booksId ); 
}


void disPlaysBooksInPage (){
	
	if ( totalBooks == 0 ){
		printf("Sach rong ! Xin vui long nhap them sach.\n");
		return; 
	} 
	
	int back = 1;
	int choosePage;
	char choicePage[10];
	int page = 1 ; 
	char pageInput[10];
	int targetPage;
	
    int totalPages;
	if ( totalBooks % booksPerPage == 0  ){
		totalPages = totalBooks / booksPerPage;
	} else {
		totalPages = totalBooks / booksPerPage + 1 ;
	}
	
     while (back){
     	
     	system("cls"); 
     	printf("\n==================================== TOTAL PAGE %d ===============================\n" , totalPages ); 
	    printf("\n==================================== PAGE %d/%d ====================================\n" , page , totalPages );
		
		for ( int i = 1 ; i <= 81 ; i++ ){
			printf("-"); 
		} 
		
		printf("\n|%-7s|%-30s|%-20s|%-10s|%-8s|\n", "ID", "Title", "Author", "Year", "Quantity");
		for ( int i = 0 ; i <= 81 ; i++ ){
			printf("-"); 
		} 
		
		int start = ( page - 1 ) * booksPerPage;
		int end  = start + booksPerPage;
		
		if ( end > totalBooks ){
			end  = totalBooks ; 
		} 
		
		for ( int i = start ; i < end ; i++ ){	
			printf("\n|%-7d|%-30s|%-20s|%-10d|%-8d|\n", 
                books[i].bookId, books[i].title, books[i].author, 
                books[i].publishYear, books[i].quantity);  
				
		for ( int j = 1 ; j <= 81 ; j++ ){
			printf("-");   
	    	} 
		} 
		
		printf("\nHien thi %d sach.\n" , ( end - start ));
 
		int continueDisplay = 1 ; 
		while(continueDisplay) {  
            printf("\nNhap 1 de tro ve trang.\n");
            printf("Nhap 2 de thoat.\n");
            printf("Nhap 3 de tiep tuc trang.\n");
            printf("Nhap 4 de hien thi trang ban muon den tu 1 - %d.\n" , totalPages);  
             do {
            	
            	printf("\nNhap lua chon:");
            	fgets ( choicePage , 10 , stdin );
            	choicePage[strcspn(choicePage , "\n")] = '\0';
            	
            	if ( strlen(choicePage) == 0 || strcasecmp(choicePage , " ") == 0){
            		printf("\nBan nhap lua chon thi khong duoc de trong.");
				} else if ( !isValidNum(choicePage) ){
					printf("\nID phai nhap la so nguyen.");
				} else {
					choosePage = atoi(choicePage);
				}

			} while ( strlen(choicePage) == 0 || 
			          strcasecmp(choicePage , " ") == 0 || 
					  !isValidNum(choicePage) );
			switch (choosePage){
                case 1:
                    if (page==1) {
                    	printf("\nBan dang xem trang dau - Khong the xem trang truoc.\n");
                    	continueDisplay = 1; 
                    	printf("\nNhap bat ki de tro ve lua chon.");
                    	getchar();
                    }else{
                        page--;
                    }
                    continueDisplay = 0;
                    break;
                case 2:
                    back=0;
                    continueDisplay = 0; 
                    break;
                case 3:
                    if (page==totalPages) {
                    	printf("\nBan dang xem trang cuoi - Khong the xem trang tiep theo.\n"); 
                    	printf("\nNhap bat ki de tro ve lua chon.");
                    	getchar();
                    }else {
                        page++;
                    }
                    continueDisplay = 0;
                    break;
                case 4:
				   
					 do {
					 	
					 	printf("\nNhap trang ban muon hien thi:");
					 	fgets(pageInput , 10 , stdin );
					 	pageInput[strcspn(pageInput , "\n")] = '\0';
					 	
					 	if( strlen(pageInput) == 0 || strcasecmp( pageInput , " ") == 0 ){
					 		printf("\nSo trang khong the bo trong.");
					 		continue;
						 } else if ( !isValidNum(pageInput) ){
						 	printf("\nSo trang phai la so nguyen duong tu 1 den %d." , totalPages);
						 	continue;
						 } else {
						 	targetPage = atoi(pageInput);
						 }
					 	   
					 	 if ( targetPage < 1 || targetPage > totalPages ){
					 	 	printf("\nSo trang khong hop le - Xin vui long nhap lai.");
						  } else {
						  	page = targetPage;
						  	continueDisplay = 0;
						  	break;
						  }
					 	
					 } while( strlen(pageInput) == 0 ||
					          strcasecmp( pageInput , " ") == 0 ||
							  !isValidNum(pageInput) ||
							  targetPage < 1 || 
							  targetPage > totalPages );
							  
						  
                default:
                    printf("\nLoi! Moi ban nhap tu 1-4!!\n");
            }
        } 
	} 
}

void deleteInformationById (){
	
	if ( totalBooks == 0 ){
		printf("\nDanh sach rong - Xin vui long nhap them danh sach.");
		return; 
	} 
	
	int booksId; 
	char idString[10];
	char confirm[10];
	 
	do {
		
		printf("Nhap ID de xoa : ");
		fgets( idString , 10 , stdin );
		idString [strcspn(idString , "\n")] = '\0';
		
		if ( strlen(idString) == 0 || strcasecmp (idString , " ") == 0 ){
			printf("\nID khong the de trong - Vui long nhap ID.\n"); 
		} else if ( !isValidNum (idString) ){
			printf("\nID phai nhap so nguyen.\n");
		} else {
			booksId = atoi( idString); 
		} 
		
		if ( idBooksExisted( booksId) == 1 ){
	    	printf("\nDanh sach khong ton tai ma nay.\n");
    	} 
    	
    	for ( int i = 0 ; i < totalBorrow ; i++ ){
    		if ( borrows[i].status == 1 && borrows[i].bookId == booksId ){
    			printf("Khong the xoa sach - Vi da co nguoi muon.\n");
				return; 
			} 
		} 
		 
	} while ( strlen(idString ) == 0 ||
	          strcasecmp( idString , " ") == 0 ||
			  !isValidNum(idString) ||
			  idBooksExisted(booksId) == 1 ); 
			  
		system("cls"); 
    	printf("Ban co chac muon xoa sach nay ko ?\n");
		printf("[Y]Yes      [N]No\n");
		printf("\nChoose :");
		
		fgets ( confirm , 10 , stdin ); 
		confirm[strcspn(confirm , "\n" )] = '\0';
	
	     if ( strcmp( confirm , "y") == 0 || strcmp( confirm , "Y") == 0 ){
	     	for ( int i = 0 ; i < totalBooks - 1 ; i++ ){
	     		if ( books[i].bookId == booksId ){
	     			for ( int j = i ; j < totalBooks - 1 ; j++ ){
	     				books[j] = books[j+1];
					 }
					 totalBooks--;
					 break;
				 }
			 }
			 printf("\nXoa sach thanh cong.\n");
		 } else {
		 	printf("\nHuy xoa sach.\n");
		 }
} 


void searchBook (){
	
	if ( totalBooks == 0 ){
		printf("Danh sach rong ! Khong co sach de tim kiem.");
		return; 
	} 
	
	char keyWord[50];
	int found = 0; 
	char choice[10]; 
	int continueSearch = 1; 
	
	while (continueSearch){
	found = 0; 
	do {
		
		printf("\n=================== Find Book By Keyword ===================\n"); 
		printf("\nNhap ten sach ban muon tim:"); 
		fgets (keyWord , 50 , stdin );
		keyWord[strcspn(keyWord , "\n")] = '\0';
		
		if ( strlen (keyWord) == 0 || strcmp(keyWord , " ") == 0 ){
			printf("Ten sach khong duoc de trong-Vui long nhap lai."); 
		}
		
	} while( strlen (keyWord) == 0 || strcmp(keyWord , " ") == 0 ); 

	for ( int i = 0 ; i < totalBooks ; i++ ){
		
			char tempTitle[50];
			char tempKeyWord[50]; 
		
		strcpy( tempTitle , books[i].title);
		for ( int j = 0 ; tempTitle[j] != '\0' ; j++ ){
			if ( tempTitle[j] >= 'A' && tempTitle [j]<= 'Z'){
				tempTitle[j] = tempTitle[j] + 32;
			}
		}
		
		strcpy( tempKeyWord , keyWord );
		for ( int j = 0 ; tempKeyWord[j] != '\0' ; j++ ){
			if ( tempKeyWord[j] >= 'A' && tempKeyWord[j] <= 'Z' ){
				tempKeyWord[j] = tempKeyWord[j] + 32;
			}
		}
		
		if ( strstr(tempTitle , tempKeyWord )){
			found++;
		}
	} 
	
	if ( found == 0 ){
		printf("\n\nKhong tim thay sach nao phu hop voi tu khoa %s.\n" , keyWord ); 
	} else {
		printf("\n==================== Search Result ====================\n");
	
		for ( int i = 1 ; i <= 81 ; i++ ){
			printf("-"); 
		} 
		printf("\n|%-7s|%-30s|%-20s|%-10s|%-8s|\n", "ID", "Title", "Author", "Year", "Quantity");
		for ( int i = 0 ; i <= 81 ; i++ ){
			printf("-"); 
		} 
		
		int printedCount = 0; 
		for (int i = 0; i < totalBooks; i++) {
			char tempTitle[50];
			char tempKeyWord[50];
			
			strcpy(tempTitle , books[i].title);
			for ( int j = 0 ; tempTitle[j] ; j++ ){
				if(tempTitle[j] >= 'A' && tempTitle[j] <= 'Z'){
					tempTitle[j] = tempTitle[j] + 32;
				}
			}
			strcpy(tempKeyWord , keyWord );
			for ( int j = 0 ; tempKeyWord[j] ; j++ ){
				if( tempKeyWord[j] >= 'A' && tempKeyWord[j] <= 'Z'){
					tempKeyWord[j] = tempKeyWord[j] + 32;
				}
			}
			
            if ( strstr(tempTitle, tempKeyWord )) {
                printf("\n|%-7d|%-30s|%-20s|%-10d|%-8d|\n", 
                    books[i].bookId, books[i].title, books[i].author, 
                    books[i].publishYear, books[i].quantity);
                for (int j = 1; j <= 81; j++) {
                    printf("-");   
                } 
                  printedCount++; 
        	} 	
        } 
             printf("\n\nTim thay %d sach phu hop.\n" , printedCount );
    }
     do {
        	printf("\nBan co muon tim kiem tiep khong?\n");
			printf("[Y]Yes                    [N]No\n");
			printf("\nEnter choice:"); 
			fgets(choice , 10 , stdin);
			choice[strcspn(choice , "\n")] = '\0'; 
			
			if ( strlen(choice) == 0 || strcasecmp(choice , " ") == 0 ){
				printf("\nLua chon khong duoc de trong - Xin vui long nhap lai.\n"); 
			} else if ( strcmp(choice , "y") == 0 || strcmp(choice , "Y") == 0 ){
				continueSearch = 1; 
				break; 
			} else if ( strcmp(choice , "n") == 0 || strcmp(choice , "N") == 0 ){
				continueSearch = 0 ;
				break; 
			} else{
				printf("\nLua chon khong hop le - Xin vui long nhap Y hoac N.\n"); 
			} 
			
		} while ( strlen(choice) == 0 || strcasecmp(choice , " ") == 0); 
    }
}
    
    
void addBooksBorrow(){
	
	if ( totalBooks == 0 ){
		printf("\nSach rong - Xin vui long them sach.");
		return; 
	} 
	 
    
    int continueBorrow = 1; 
    while (continueBorrow){
    	printf("\n=============== Enter Information Books Borrow ===============");
		printf("\n------Muon %d sach------" , totalBorrow + 1 ); 
		
		
		borrows[totalBorrow].Id = ++nextBooksBorrow;
		printf("\nID cua sach muon %d " , borrows[totalBorrow].Id);
		
		
        char bookIdStr[50];  
        
		do {
			printf("\nID cua sach : ");
			fgets(bookIdStr , 50 , stdin );
			bookIdStr[strcspn(bookIdStr , "\n")] = '\0';
			
			if ( strlen(bookIdStr) == 0 || strcasecmp(bookIdStr , " ") == 0 ){
				printf("\nMa sach khong duoc de trong - Xin vui long nhap lai."); 
				continue; 
			} else if ( !isValidNum(bookIdStr)){
				printf("\nMa sach phai nhap so nguyen."); 
				continue; 
			} else {
				borrows[totalBorrow].bookId = atoi(bookIdStr); 
			} 
			
			if ( idBooksExisted(borrows[totalBorrow].bookId) == 1 ){
				printf("\nID sach khong ton tai.\n"); 
			} 
			
		} while( strlen(bookIdStr) == 0 || 
		         strcasecmp(bookIdStr , " ") == 0 ||
				 !isValidNum(bookIdStr) ||
				 idBooksExisted(borrows[totalBorrow].bookId) == 1 ); 
				 
		 int foundIndex = -1;
         for (int i = 0; i < totalBooks; i++) {
              if (books[i].bookId == borrows[totalBorrow].bookId) {
                  foundIndex = i;
                  break;
              }
         }
         
          if (foundIndex != -1) {
            if (books[foundIndex].quantity > 0) {
                books[foundIndex].quantity--;
            } else {
                printf("\nSach nay da het trong kho. Khong the muon.\n");
                continueBorrow = 1;
            }
        } else {
            printf("\nKhong tim thay sach trong kho.\n");
            continueBorrow = 1;
        }
		
		printf("\n=============== Enter The Book Borrow Date ===============\n"); 
		
		char dayBorrow[50];
        char monthBorrow[50];
        char yearBorrow[50]; 

	do {
		do {
			printf("\nNhap ngay muon :"); 
			fgets( dayBorrow , 50 , stdin );
			dayBorrow[strcspn(dayBorrow , "\n")] = '\0';
			
			if ( strlen(dayBorrow) == 0 || strcmp(dayBorrow , " ") == 0 ){
				printf("\nNgay muon khong the bo trong - Xin vui long nhap."); 
			} else if( !isValidNum(dayBorrow) ){
				printf("\nNgay phai nhap so nguyen."); 
			} else {
				borrows[totalBorrow].borrowDate.day = atoi(dayBorrow); 
			} 
				
		} while( strlen(dayBorrow) == 0 || 
		         strcmp(dayBorrow , " ") == 0 || 
				 !isValidNum(dayBorrow)); 
		
		do {
			printf("Nhap thang muon :");
			fgets( monthBorrow , 50 , stdin );
			monthBorrow[strcspn(monthBorrow , "\n")] = '\0';
			
			 if ( strlen(monthBorrow) == 0 || strcmp(monthBorrow , " ") == 0 ){
				printf("\nThang muon khong the bo trong - Xin vui long nhap."); 
			} else if( !isValidNum(monthBorrow) ){
				printf("\nThang phai nhap so nguyen."); 
			} else {
				borrows[totalBorrow].borrowDate.month = atoi(monthBorrow); 
			} 
			 
		} while(strlen(monthBorrow) == 0 || 
		        strcmp(monthBorrow , " ") == 0 || 
				!isValidNum(monthBorrow));
		 
		do {
			printf("Nhap nam muon :");
			fgets(yearBorrow , 50 , stdin );
			yearBorrow[strcspn(yearBorrow , "\n")] = '\0';
			
			 if ( strlen(yearBorrow) == 0 || strcmp(yearBorrow , " ") == 0 ){
				printf("\nNam muon khong the bo trong - Xin vui long nhap."); 
			} else if( !isValidNum(yearBorrow) ){
				printf("\nNam phai nhap so nguyen."); 
			} else {
				borrows[totalBorrow].borrowDate.year = atoi(yearBorrow); 
			} 
			 
		} while(strlen(yearBorrow) == 0 || 
		        strcmp(yearBorrow , " ") == 0 || 
				!isValidNum(yearBorrow)); 
		
		if ( !isValidDate (borrows[totalBorrow].borrowDate.day , borrows[totalBorrow].borrowDate.month , borrows[totalBorrow].borrowDate.year )){
			printf("\nNgay thang nam khong hop le - Xin vui long nhap lai.\n"); 
		} else {
			break; 
		} 	
    } while(1);
    
    int bookIndex = -1;
	for ( int i = 0 ; i < totalBooks ; i++ ){
		if (books[i].bookId == borrows[totalBorrow].bookId){
			bookIndex = i;
			break; 
		} 
	} 
	
	if (bookIndex != -1) {
            if (books[bookIndex].publishYear > borrows[totalBorrow].borrowDate.year) {
                printf("\nSach khong the xuat ban sau nam muon!\n");
                printf("Nam xuat ban: %d\n", books[bookIndex].publishYear);
                printf("Nam muon sach: %d\n", borrows[totalBorrow].borrowDate.year);
                printf("Vui long kiem tra lai thong tin sach hoac ngay muon.\n");
                
                books[bookIndex].quantity++;
                continue; 
            }
   }
    
    char borrowerName[50]; 
    do {
    	
    	printf("Nhap ten cua nguoi muon :");
    	fgets( borrowerName , 50 , stdin );
		borrowerName[strcspn( borrowerName , "\n")] = '\0';
		
		if ( strlen(borrowerName) == 0 || strcmp(borrowerName , " ") == 0  ){
			printf("\nTen nguoi muon khong duoc de trong."); 
		} else {
			strcpy(borrows[totalBorrow].borrowerName, borrowerName); 
		} 	
	} while(strlen(borrowerName) == 0 || strcmp(borrowerName , " ") == 0 ); 
	
	
	borrows[totalBorrow].status = 1; 
	
	
	totalBorrow++;  
	
	printf("\nDa muon sach thanh cong.\n");
	
    printf("\n");
	for ( int i = 0 ; i < 81 ; i++ ){
		printf("-"); 
	} 
	printf("\n|%-78s|" , "                                THONG TIN SACH MUON");
    printf("\n");
    for ( int i = 1 ; i <= 81 ; i++ ){
        printf("-"); 
    } 
    
    printf("\n|%-10s|%-15s|%-30s|%-20s|\n", "Borrow ID", "Book ID", "Borrow Date", "Borrower Name");
    
    for ( int i = 0 ; i <= 81 ; i++ ){
        printf("-"); 
    } 
    
    int lastIndex = totalBorrow - 1;
    printf("\n|%-10d|%-15d|%02d/%02d/%-24d|%-20s|\n", 
           borrows[lastIndex].Id, 
           borrows[lastIndex].bookId, 
           borrows[lastIndex].borrowDate.day,
           borrows[lastIndex].borrowDate.month,
           borrows[lastIndex].borrowDate.year,
           borrows[lastIndex].borrowerName);
    
    for ( int i = 0 ; i <= 81 ; i++ ){
        printf("-"); 
    } 
    
       char choose[10]; 
       
	do {
        	printf("\nBan co muon sach tiep khong?\n");
			printf("[Y]Yes                    [N]No\n");
			printf("\nNhap lua chon:"); 
			fgets(choose , 50 , stdin);
			choose[strcspn(choose , "\n")] = '\0'; 
			
			if ( strlen(choose) == 0 || strcasecmp(choose , " ") == 0 ){
				printf("\nLua chon khong duoc de trong - Xin vui long nhap lai.\n"); 
			} else if ( strcmp(choose , "y") == 0 || strcmp(choose , "Y") == 0 ){
				continueBorrow = 1; 
				break; 
			} else if ( strcmp(choose , "n") == 0 || strcmp(choose , "N") == 0 ){
				continueBorrow = 0 ;
				break; 
			} else{
				printf("\nLua chon khong hop le - Xin vui long nhap Y hoac N.\n"); 
			} 
			
	} while ( strlen(choose) == 0 || strcasecmp(choose , " ") == 0); 	
											  
  }
} 

int isValidDate( int day , int month , int year ){
	
    	if ( day < 1 ){
        	return 0; 
         } 
   
        if ( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 ){
        	if ( day > 31 ){
        		return 0; 
     	   } 
        } 
    
        if ( month == 4 || month == 6 || month == 9 || month == 11 ){
        	if ( day > 30 ){
        		return 0; 
    		} 
    	} 
	
    	if ( month == 2 ){
            if ( (year % 4 == 0 && year % 100 != 0 ) || ( year % 400 == 0 ) ) {
                  if ( day > 29 ){
                     return 0; 
                  }
           } else {
                  if ( day > 28 ){
                     return 0; 
                  } 
            }
        }
    
        if ( month < 1 || month > 12 ){
        	return 0; 
    	} 
	
    	if ( year < 1900 || year > 2025 ){
     		return 0; 
    	} 
            return 1; 	
} 


void returnBooks(){
	
	if( totalBorrow == 0 ){
		printf("\nBan chua muon quyen sach nao.");
		return; 
	} 
	
	char borrowID[50]; 
    char dayReturn[50]; 
    char monthReturn[50];
    char yearReturn[50]; 
    int borrowId; 
    int borrowIndex = -1;

		
		printf("\n==================Enter Information Borrow==================\n");
	 
 do{
 	int found = 0; 
	do {
		printf("\nNhap ID muon : ");
		fgets (borrowID , 50 , stdin );
		borrowID[strcspn(borrowID , "\n")] = '\0';
		
		if(strlen(borrowID) == 0 || strcmp(borrowID , " ") == 0 ){
			printf("\nMa phieu muon khong duoc de trong.\n"); 
		} else if ( !isValidNum(borrowID)){
			printf("\nMa phieu muon phai nhap so nguyen.\n"); 
		} else {
			borrowId = atoi(borrowID); 
		} 
	
    } while (strlen(borrowID) == 0 || 
	         strcmp(borrowID , " ") == 0 || 
			 !isValidNum(borrowID)  );
			 
			 
		for ( int i = 0 ; i < totalBorrow ; i++ ){
			if ( borrows[i].Id == borrowId ){
		    	found = 1;
	    		borrowIndex = i; 
			break; 
	    	} 
        }
		
		if ( !found ){
			printf("\nMa phieu sach khong ton tai.\n");  
		} else {
			break; 
		} 
			 
  } while(1); 


	if (borrows[borrowIndex].status == 0 ){
		printf("\nSach nay da duoc tra roi.\n"); 
		return; 
	} 
	
	for ( int i = 0 ; i < totalBooks ; i++ ){
		if ( books[i].bookId == borrows[borrowIndex].bookId ){
			books[i].quantity++;
			break; 
		} 
	} 
			 
    do {
    	
        do {
            printf("\nNhap ngay tra: "); 
            fgets(dayReturn, 50, stdin);
            dayReturn[strcspn(dayReturn, "\n")] = '\0';
            
            if (strlen(dayReturn) == 0 || strcmp(dayReturn, " ") == 0) {
                printf("\nNgay tra khong the bo trong - Xin vui long nhap.\n"); 
            } else if (!isValidNum(dayReturn)) {
                printf("\nNgay phai nhap so nguyen.\n"); 
            } else {
                borrows[borrowIndex].returnDate.day = atoi(dayReturn);
            }
        } while(strlen(dayReturn) == 0 || 
		         strcmp(dayReturn , " ") == 0 || 
				 !isValidNum(dayReturn));
        
        do {
            printf("\nNhap thang tra: ");
            fgets(monthReturn, 50, stdin);
            monthReturn[strcspn(monthReturn, "\n")] = '\0';
            
            if (strlen(monthReturn) == 0 || strcmp(monthReturn, " ") == 0) {
                printf("\nThang tra khong the bo trong - Xin vui long nhap.\n"); 
            } else if (!isValidNum(monthReturn)) {
                printf("\nThang phai nhap so nguyen.\n"); 
            } else {
                borrows[borrowIndex].returnDate.month = atoi(monthReturn);
            }
        } while(strlen(monthReturn) == 0 || 
		         strcmp(monthReturn , " ") == 0 || 
				 !isValidNum(monthReturn));
        
        do {
            printf("\nNhap nam tra: ");
            fgets(yearReturn, 50, stdin);
            yearReturn[strcspn(yearReturn, "\n")] = '\0';
            
            if (strlen(yearReturn) == 0 || strcmp(yearReturn, " ") == 0) {
                printf("\nNam tra khong the bo trong - Xin vui long nhap.\n"); 
            } else if (!isValidNum(yearReturn)) {
                printf("\nNam phai nhap so nguyen.\n"); 
            } else {
                borrows[borrowIndex].returnDate.year = atoi(yearReturn);
            }
        } while(strlen(yearReturn) == 0 || 
		        strcmp(yearReturn , " ") == 0 || 
				!isValidNum(yearReturn));
        
        if (!isValidDate(borrows[borrowIndex].returnDate.day, 
                        borrows[borrowIndex].returnDate.month, 
                        borrows[borrowIndex].returnDate.year)) {
            printf("\nNgay thang nam tra khong hop le - Xin vui long nhap lai.\n"); 
        } else {
            if (borrows[borrowIndex].returnDate.year < borrows[borrowIndex].borrowDate.year ||
                (borrows[borrowIndex].returnDate.year == borrows[borrowIndex].borrowDate.year && 
                 borrows[borrowIndex].returnDate.month < borrows[borrowIndex].borrowDate.month) ||
                (borrows[borrowIndex].returnDate.year == borrows[borrowIndex].borrowDate.year && 
                 borrows[borrowIndex].returnDate.month == borrows[borrowIndex].borrowDate.month && 
                 borrows[borrowIndex].returnDate.day <= borrows[borrowIndex].borrowDate.day)) {
                printf("\nNgay tra phai sau ngay muon. Vui long nhap lai.\n");
                continue;
            }
            break;
        }
    } while(1);
    
     borrows[borrowIndex].status = 0;
	 printf("\nBan da tra sach thanh cong.\n"); 
  
} 


void disPlayBookBorrow(){
	
	
	if ( totalBorrow == 0 ){
		printf("\nDanh sach phieu muon trong.");
		return; 
	} 
	
	int totalPages;
	int back = 1; 
    int page = 1; 
    
	if ( totalBorrow % booksPerPage == 0  ){
		totalPages = totalBorrow / booksPerPage;
	} else {
		totalPages = totalBorrow / booksPerPage + 1 ;
	}
	
	while ( back ){
		
		system("cls"); 
     	printf("\n================================================== TOTAL PAGE %d ========================================\n" , totalPages ); 
	    printf("\n================================================== PAGE %d/%d =============================================\n" , page , totalPages );
		
		for ( int i = 1 ; i <= 123 ; i++ ){
			printf("-"); 
		} 
		
		printf("\n|%-10s|%-15s|%-15s|%-15s|%-30s|%-20s|%-10s|\n", "Borrow ID", "Book ID" , "Borrow Date" , "Return Date" , "Book Name" , "Borrower Name" , "Status"); 

		
		for ( int j = 1 ; j <= 123; j++ ){
		    	printf("-");   
	    	 } 
		
		int start = (page - 1) * booksPerPage;
		int end  = start + booksPerPage;
		
		if ( end > totalBorrow ){
			end  = totalBorrow; 
		} 
		
		for ( int i = start ; i < end ; i++ ){	
		    char bookTitle[50] ;
			for ( int j = 0 ; j < totalBooks ; j++ ){
				if ( books[j].bookId == borrows[i].bookId ){
					strcpy(bookTitle , books[j].title );
					break; 
				} 
			} 
			
		char statusStr[20];
		if ( borrows[i].status == 1 ){
			strcpy(statusStr , "Dang muon"); 
		} else {
			strcpy(statusStr , "Da tra"); 
		} 
			if (borrows[i].status == 1) {

            printf("\n|%-10d|%-15d|%02d/%02d/%-9d|%-15s|%-30s|%-20s|%-10s|\n", 
                   borrows[i].Id, 
                   borrows[i].bookId, 
                   borrows[i].borrowDate.day,
                   borrows[i].borrowDate.month,
                   borrows[i].borrowDate.year,
                   "Chua tra",  
                    bookTitle, 
                    borrows[i].borrowerName,
                    statusStr ); 
           } else {

           printf("\n|%-10d|%-15d|%02d/%02d/%-9d|%02d/%02d/%-9d|%-30s|%-20s|%-10s|\n", 
                  borrows[i].Id, 
                  borrows[i].bookId, 
                  borrows[i].borrowDate.day,
                  borrows[i].borrowDate.month,
                  borrows[i].borrowDate.year,
                  borrows[i].returnDate.day,
                  borrows[i].returnDate.month,
                  borrows[i].returnDate.year, 
                  bookTitle, 
                  borrows[i].borrowerName,
                  statusStr ); 
}
                
		for ( int j = 1 ; j <= 123 ; j++ ){
			printf("-");   
	    	} 
		} 
		
		printf("\nHien thi %d sach muon.\n" , ( end - start ));
		
		int continuePage = 1;
		char choosePages[10]; 
		char pageInput[10];
		int targetPage; 
		int choicePage;
		
		while ( continuePage){
			
			printf("\n1.Nhap 1 de tro ve trang.");
			printf("\n2.Nhap 2 de thoat.");
			printf("\n3.Nhap 3 de sang trang tiep theo.");
			printf("\n4.Nhap 4 de hien thi trang ban muon den tu 1 - %d.\n" , totalPages);
			
			do {
				printf("\nNhap lua chon cua ban:");
				fgets( choosePages , 10 , stdin );
				choosePages[strcspn( choosePages , "\n")] = '\0';
				
				if(strlen(choosePages) == 0 || strcmp(choosePages , " ") == 0 ){
					printf("\nKhong duoc de trong."); 
				} else if( !isValidNum(choosePages) ){
					printf("\nBan phai nhap so nguyen tu 1 den 4."); 
				} else {
					 choicePage = atoi(choosePages); 
				} 
					
			} while( strlen(choosePages) == 0 || 
			         strcmp(choosePages , " ") == 0 || 
					 !isValidNum(choosePages) ); 

			 switch (choicePage){
			 	case 1:
				    if (page == 1 ){
				        printf("\nBan dang o trang dau.Khong the lui.\n"); 
				        printf("\nNhap thu bat ki de tra ve lua chon.");
                    	getchar();
					} else {
						page--; 
					} 
					continuePage = 0;
					break; 
				case 2:
				    back = 0;
					continuePage = 0;
					break;
				case 3:
				    if( page == totalPages ){
				    	printf("\nBan dang o trang cuoi.Khong the tien.\n"); 
				    	printf("\nNhap thu bat ki de tra ve lua chon.");
                    	getchar();
					} else {
						page++; 
					} 
					continuePage = 0;
					break;
				case 4:
					do {
				        printf("\nNhap trang ban muon xem (1 - %d): ", totalPages);
                        fgets(pageInput, 10, stdin);
                        pageInput[strcspn(pageInput, "\n")] = '\0';
                        
                        if(strlen(pageInput) == 0 || strcmp(pageInput, " ") == 0){
                            printf("\nKhong duoc de trong.\n");
                        } else if(!isValidNum(pageInput)){
                            printf("\nPhai nhap so nguyen.\n");
                        } else {
                            targetPage = atoi(pageInput);
                        }
                        
                        if(targetPage < 1 || targetPage > totalPages){
                            printf("\nTrang khong hop le. Vui long nhap lai!\n");
                        } else {
                            page = targetPage;
                            continuePage = 0;
                            break;
                        } 
                    } while(strlen(pageInput) == 0 ||
                            strcmp(pageInput, " ") == 0 ||
                            !isValidNum(pageInput) ||
                            targetPage < 1 || 
                            targetPage > totalPages);
                           
                     break; 
                default:
                    printf("\nLua chon khong hop le! Vui long chon 1-4.\n");    
                    break; 
			 } 
      	}
	}
}
