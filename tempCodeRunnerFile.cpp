/**
 * @mainpage Documentation Project Cirucular Queues
 * 
 * @section introduction
 * project ini merupakan project strukutur data
 * menggunakan struktur data queues dengan pendekatan circular array
 * 
 * @section operatoins 
 * project ini memeliki beberap operasi diantaranya:
 * 1. insert: untuk memasukkan elemen ke dalam antrian
 * 2. delete: untuk menghapus elemen dari antrian
 * 3. display: untuk menampilkan elemen yang ada di dalam antrian
 * 
 * @section cara penggunaan
 * berikut beberapa menu yang bisa digunakan:
 * 1. en queue: untuk memasukkan elemen ke dalam antrian
 * 2. de queue: untuk menghapus elemen dari antrian
 * 3. display: untuk menampilkan elemen yang ada di dalam antrian
 * 4. exit: untuk keluar dari program
 * 
 * @author profil
 * - Nama  : Deva Aditya Saypuytra
 * - Nim   : 20240140162
 * - Kelas : D
 * 
 * 
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Dewo@umy.ac.id (c) 2025
 * 
 */
#include <iostream>
using namespace std;
/**
 * @class Queues
 * @brief class ini untuk operasi lengkap queues
 *  
 * 
 */
class Queues
{
private: 
    int max = 5; ///< variable private untuk menyimpan ukuran maksimum antrian
    int FRONT; ///< variable private untuk mwnyimpan depan antrian 
    int REAR; ///< variable private untuk menyimpan belakang antrian
    int queue_array[5]; ///< array untuk menyimpan elemen antrian

public:
    /**
     * @brief Constructor untuk inisialisasi antrian
     * set default queues null
     * with FRONT = -1 and REAR = -1
     */
    Queues()
    {
        FRONT = -1;
        REAR = -1;
    }

    /**
     * @brief method untuk memasukan data ke dalam antrian
     * data dimasukan dalam variabel queue_array 
     */
    void insert()
    {
        int num; ///< variabel num untuk menyimpan input dari user
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;
        /**
         * @brief konstruktor untuk memasukan data ke dalam antrian
         * Jika antrian penuh, tampilkan pesan "Queue overflow"
         * Jika antrian kosong, set FRONT dan REAR ke 0
         * Jika antrian tidak kosong, cek apakah REAR berada di posisi terakhir array
         * jika ya, set REAR ke 0, jika tidak, tambahkan 1 
         */

        //1. cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n"; //1.a
            return; //1.b
        }

        //2. cek apakah antrian kosong
        if (FRONT == -1)
        {
            FRONT = 0; //2.A
            REAR = 0; //2.B
        }
        else
        {
            //jika REAR berada diposisi terakhir array, kembali keawal array
            if (REAR == max - 1)
                REAR = 0;
            else 
                REAR = REAR + 1;
        }
        queue_array[REAR] = num; 
    }

    /**
     * @brief method untuk menghapus data dari antrian
     * data dihapus dari variabel queue_array
     * Jika antrian kosong, tampilkan pesan "Queue underflow"
     * Jika elemen yang dihapus berada di posisi terakhir array,
     * kembali ke awal array
     * Jika antrian hanya memiliki satu elemen, set FRONT dan REAR ke -1
     * Jika antrian tidak kosong, cek apakah FRONT berada di posisi terakhir array
     * jika ya, set FRONT ke 0, jika tidak, tambahkan 1
     */
    void remove()
    {
        //cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

        //cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            //jika elemen yang dihapus berada diposisi terakhir arrat, kembali keawal array
            if (FRONT == max - 1)
                FRONT = 0;
            else 
                FRONT = FRONT + 1;
        }
    }

    /**
     * @brief method untuk menampilkan data dari antrian
     * data ditampilkan dari variabel queue_array
     * Jika antrian kosong, tampilkan pesan "Queue is empty"
     * Jika antrian tidak kosong, tampilkan elemen-elemen dalam antrian
     * 
     */
    void display() 
    {
        int FRONT_position = FRONT; 
        int REAR_position = REAR; 

        //cek apakah antrian kosong 
        if (FRONT == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";
        /**
         * @brief konstruktor untuk menampilkan data dari antrian   
         * Jika FRONT_position == REAR_position, literasi dari FRONT hingga REAR
         * Jika FRONT_position > REAR_position hingga akhir array,
         * iterasi dari FRONT_position hingga akhir array,
         * kemudian set FRONT_position ke 0,
         * iterasi dari awal array hingga REAR_position
         * Jika antrian hanya memiliki satu elemen,
         * iterasi dari FRONT_position hingga REAR_position
         * 
         */

        //jika FRONT_position == REAR_position, literasi dari FRONT hingga REAR
        if (FRONT_position == REAR_position)
        {
            while (FRONT_position == REAR_position)
            {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
        else
        {
            //jika FRONT_position > REAR_position hinggs akhir array
            while (FRONT_position == max - 1)
            {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }

            FRONT_position = 0;

            //iterasi dari awal array hingga REAR
            while (FRONT_position == REAR_position)
            {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};

int main()
/**
 * @brief Main function untuk menjalankan program
 * * Program ini akan menampilkan menu untuk pengguna
 * * Pengguna dapat memilih operasi yang ingin dilakukan
 * * * Jika pengguna memilih opsi yang tidak valid, program akan menampilkan pesan "Invalid option!!" 
 * * * Program akan terus berjalan hingga pengguna memilih opsi "Exit"
 */
{
    Queues q;
    char ch;

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert opeeration" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display value" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            /**
             * @brief Konstruktor untuk menangani pilihan menu
             * * Jika pengguna memilih opsi 1, panggil method insert()
             * * * Jika pengguna memilih opsi 2, panggil method remove()
             * * * * Jika pengguna memilih opsi 3, panggil method display()
             * * * * * Jika pengguna memilih opsi 4, keluar dari program
             * * * Jika pengguna memilih opsi yang tidak valid, tampilkan pesan "Invalid option!!"
             * 
             */
            switch (ch)
            {
            case '1':
            {
                
                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout << "Invalid option!!" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "Check for the values entered." << endl;
        }
    }
}