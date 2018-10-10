                  /*************************************************************************\
                  *                                                                         *
                  *        Course:  CS213 - Programming II  - 2018                          *
                  *        Title:   Assignment I - Task 1 - Problem 1                       *
                  *        Program: CS213-2018-A1-T1-P1                                     *
                  *        Purpose: Skeleton code for the student to start working          *
                  *        Author:  Dr. Mohammad El-Ramly                                   *
                  *        Date:    10 August 2018                                          *
                  *        Version: 1.0                                                     *
                  *        student 1: Sameh Serag Eldin Ramadan          20170113    G4     *
                  *        student 2: hazem Alaa Eldin Hassan            20170087    G4     *
                  *        student 3: mostafa Abd ElMohsen Abd ElHakam   20170000    G4     *
                  *                                                                         *
                  /*************************************************************************/
#include <iostream>
#include <iomanip>
//#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
  int* data;       // Pointer to 1-D array that will simulate matrix
  int row, col;
};

// Already implemented
void createMatrix (int row, int col, matrix& mat);

// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
					    // new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
					     // matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
       	// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
       // and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
       	// Print matrix  as follows (2 x 3)			4	 6 	  8
	       // and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

//__________________________________________

int main()
{
    matrix mat1, mat2, mat3;
    int choose = 0 ,choose2 = 0 , scalar = 0;
while (true){
    cout << "enter the fist matrix \n ";
    cin >> mat1 ;
    cout << "\n enter the second matrix \n ";
    cin >> mat2 ;

    while (true){
        cout << "\n choose what you want to do with this two matrix ? \n"
             << "1- matrix1 + matrix2 \n"
             << "2- matrix1 - matrix2 \n"
             << "3- matrix1 * matrix2 \n"
             << "4- matrix + scalar \n"
             << "5- matrix - scalar \n"
             << "6- matrix * scalar \n"
             << "7- matrix1 = matrix1 + matrix2 \n"
             << "8- matrix1 = matrix1 - matrix2 \n"
             << "9- matrix = matrix + scalar \n"
             << "10- matrix = matrix - scalar \n"
             << "11- matrix = matrix + 1 \n"
             << "12- matrix = matrix - 1 \n"
             << "13- matrix1 == matrix 2\n"
             << "14- matrix1 != matrix 2\n"
             << "15- matrix1 == matrix 2\n"
             << "16- if matrix Square \n"
             << "17- if matrix Symmetric \n"
             << "18- if matrix Identity \n"
             << "19- the transpose of the  matrix \n";

        cin >> choose  ;
        cout << endl ;

        if (choose == 1){
            cout << (mat1 + mat2) << endl ;
        }
        else if (choose == 2)
            cout << (mat1 - mat2) << endl ;

        else if (choose == 3)
            cout << (mat1 * mat2) << endl ;

        else if (choose == 4){
            cout << "Enter scalar that you want to add : ";
            cin >> scalar  ;
            cout << "\n which matrix do you want to add "
                 << "1- Matrix1 \n 2-Matrix2 ";
            cin >> choose2 ;
            cout << endl ;
            if (choose2 == 1)
                cout << (mat1 + scalar) << endl;
            else
                cout << (mat2 + scalar) << endl;
        }

        else if (choose == 5){

            cout << "Enter scalar that you want to Subtract  ";
            cin >> scalar ;
            cout << endl  ;

            cout << "which matrix do you want to Subtract  "
                 << "1- Matrix1 \n 2-Matrix2 ";
            cin >> choose2 ;
            cout << endl;

            if (choose2 == 1)
                cout << (mat1 - scalar) << endl;
            else
                cout << (mat2 - scalar) << endl;
        }

        else if (choose == 6)
            cout << (mat1 * mat2) << endl ;
        else if (choose == 7)
            cout << (mat1 += mat2) << endl ;
        else if (choose == 8)
            cout << (mat1 -= mat2) << endl ;

        else if (choose == 9){
            cout << "Enter scalar that you want to add";
            cin >> scalar ;
            cout << endl ;

            cout << "which matrix do you want to add "
                 << "1- Matrix1 \n 2-Matrix2 ";
            cin >> choose2 ;
            cout << endl;

            if (choose2 == 1)
                cout << (mat1 += scalar) << endl;
            else
                cout << (mat2 += scalar) << endl;
        }

        else if (choose == 10){

            cout << "Enter scalar that you want to Subtract  ";
            cin >> scalar ;
            cout << endl ;

            cout << "which matrix do you want to Subtract  "
                 << "1- Matrix1 \n 2-Matrix2 ";
            cin >> choose2 ;
            cout << endl;

            if (choose2 == 1)
                cout << (mat1 -= scalar) << endl;
            else
                cout << (mat2 -= scalar) << endl;
        }

        else if (choose == 11){

            cout << "which matrix do you want to add 1 \n "
                 << "1- Matrix1 \n 2-Matrix2 \n";
            cin >> choose2 ;

            if (choose2 == 1)
                cout << (mat1 ++) << endl;
            else
                cout << (mat2 ++) << endl;
        }

        else if (choose == 12){

            cout << "which matrix do you want to subtract 1\n  "
                 << "1- Matrix1 \n 2-Matrix2 \n";
            cin >> choose2 ;

            if (choose2 == 1)
                cout << (mat1 --) << endl;
            else
                cout << (mat2 --) << endl;
        }
/*
        else if (choose == 13)

        else if (choose == 14)

        else if (choose == 15)

        else if (choose == 16)

        else if (choose == 17)

        else if (choose == 18)

        else if (choose == 19)
*/

    }
}
return 0;
}
//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col,  matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data = new int [row * col];
  //for (int i = 0; i < row * col; i++)
    //mat.data [i] = num [i];
}

//____________________________________________________________
// += operatpr
matrix operator+= (matrix& mat1, matrix mat2){ // Add if same dimensions

    if (mat1.col ==mat2.col && mat1.row == mat2.row )
        for (int i = 0; i < mat1.row * mat1.col; i++){
            mat1.data[i] =  mat1.data[i] + mat2.data[i] ;
    }
    else
        cout << "it is not the same dimentions ";

return mat1 ;
}

//____________________________________________________________
// -= operator
matrix operator-= (matrix& mat1, matrix mat2){ // Add if same dimensions

    if (mat1.col ==mat2.col && mat1.row == mat2.row )
        for (int i = 0; i < mat1.row * mat1.col; i++){
            mat1.data[i] =  mat1.data[i] - mat2.data[i] ;
    }
    else
        cout << "it is not the same dimentions ";

return mat1 ;
}

//___________________________________________
// += operator with scaler
matrix operator+= (matrix& mat, int scalar){
    for (int i = 0 ; i < mat.col *mat.row ; i++){
        mat.data[i] = mat.data[i] + scalar ;

    }

return mat;
}

//___________________________________________________
// -= operator with - scalar
matrix operator-= (matrix& mat, int scalar){
    for (int i = 0 ; i < mat.col *mat.row ; i++){
        mat.data[i] = mat.data[i] - scalar ;

    }

return mat;

}
//__________________________________________________________
//add 1 for each element
void   operator++ (matrix& mat){
    for (int i = 0 ; i < mat.col *mat.row ; i++){
        mat.data[i] = mat.data[i] + 1 ;

    }


}

//__________________________________________________________
//sub 1 for each element
void   operator-- (matrix& mat){
    for (int i = 0 ; i < mat.col *mat.row ; i++){
        mat.data[i] = mat.data[i] - 1 ;

    }

}
//____________________________________________
// operator >>
istream& operator>> (istream& in, matrix& mat){
    int row = 0 , col = 0 ;
    cout << " Enter the row of the matrix : ";
    in >> row ;
    mat.row = row ;

    cout << "\n Enter the colom of the matrix : ";
    in >> col ;
    mat.col = col ;

    mat.data = new int [row * col] ;
    cout << "\n Enter the elements of the matrix : \n";
    for (int i = 0 ; i < mat.col *mat.row ; i++){
        in >> mat.data[i];

    }
    return in ;
}
//_____________________________________________________________________
//_____________________________________________________________________
// student 1 +
matrix operator+  (matrix mat1, matrix mat2) // Add if same dimensions
{
    matrix mat4;
    mat4.row = mat1.row;
    mat4.col = mat1.col;
    mat4.data = new int [mat1.row * mat1.col];
    if (mat1.col ==mat2.col && mat1.row == mat2.row )
        for(int i = 0 ; i< mat1.row * mat1.col ; i++){
            mat4.data[i]=mat1.data[i]+mat2.data[i];
        }
    else
        cout << "it is not the same dimension "
    return mat4;
}
//________________________________________________
// operator -
matrix operator-  (matrix mat1, matrix mat2){ // Sub if same dimensions
    matrix mat4;
    mat4.row = mat1.row;
    mat4.col = mat1.col;
    mat4.data = new int [mat1.row * mat1.col];
    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat4.data[i]=mat1.data[i]-mat2.data[i];
    }
    return mat4;
}
//_________________________________________________
// operator *
matrix operator*  (matrix mat1, matrix mat2) // Multi if col1 == row2
{
    matrix mat4;
    mat4.row = mat1.row;
    mat4.col = mat1.col;
    mat4.data = new int [mat1.row * mat1.col];

    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat4.data[i]=mat1.data[i]* mat2.data[i];
    }
    return mat4;
}
//________________________________
// Add a scalar

matrix operator+  (matrix mat1, int scalar){
    matrix mat4;
    mat4.row = mat1.row;
    mat4.col = mat1.col;
    mat4.data = new int [mat1.row * mat1.col];
    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat4.data[i]=mat1.data[i]+scalar;
    }
    return mat4;
}

//______________________________________________
// Subtract a scalar
matrix operator-  (matrix mat1, int scalar){

    matrix mat4;
    mat4.row = mat1.row;
    mat4.col = mat1.col;
    mat4.data = new int [mat1.row * mat1.col];
    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat4.data[i]=mat1.data[i]-scalar;
    }
    return mat4;
}
//______________________________________________________
// Multiple by scalar
matrix operator*  (matrix mat1, int scalar){
    matrix mat4;
    mat4.row = mat1.row;
    mat4.col = mat1.col;
    mat4.data = new int [mat1.row * mat1.col];
    for(int i = 0 ; i< mat1.row * mat1.col ; i++){
        mat4.data[i]=mat1.data[i]*scalar;
    }
    return mat4;
}

//___________________________________________________
//___________________________________________________
// student #3 o stream
ostream& operator<< (ostream& out, matrix mat){
    int flag = 0 ;
    for (int i = 0 ; i < mat.row ; i++){
            for (int j = 0  ; j < mat.col ; j++ ){
                    out << mat.data[flag] << " ";
                    flag++ ;
            }
    out << endl ;
    }
    return out ;


}



// cout << (mat1 + mat2) ;
    //  createMatrix (2, 3, data2, mat2);
    //  createMatrix (4, 2, data3, mat3);
    // The next code will not work until you write the functions
      //cout << mat1 << endl;
      //cout << mat2 << endl;
      //cout << mat3 << endl;

      //cout << (mat1 + mat3) << endl << endl;
      //cout << (mat3 + mat3) << endl << endl;

      //++mat1;
      //cout << mat1 << endl;

     // mat1+= mat3 += mat3;


      //cout << mat1 << endl;
      //cout << mat2 << endl;
      //cout << mat3 << endl;
      // Add more examples of using matrix
      // .......
