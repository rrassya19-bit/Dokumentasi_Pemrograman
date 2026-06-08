/**
 * @mainpage Documentation Circular Queues
 *
 * @section Introduction
 * Project ini merupakan project struktur data
 * menggunakan struktur data queues dengan pendekatan circular arrays.
 *
 * @section Operations
 * Project ini memiliki beberapa operasi antara lain:
 * 1. Insert
 * 2. Delete
 * 3. Display
 *
 * @section Cara_Penggunaan
 * Berikut beberapa menu yang bisa digunakan:
 * 1. en queue
 * 2. de queue
 * 3. display
 * 4. exit
 *
 * @author Profil
 * - nama  : Ahmad Rassya Maulana
 * - nim   : 20250140157
 * - kelas : D
 *
 * @brief
 * @version 0.1
 * @date 2026-06-08
 *
 * @copyright ahmad.rassya.ft25@mail.umy.ac.id (c) 2026
 */

#include <iostream>
using namespace std;

/**
 * @class Queues
 * @brief class ini untuk operasi lengkap queus
 */
class Queues {
private:
    int FRONT;            ///< variable private front untuk menyimpan posisi depan antrian
    int REAR;             ///< variable private rear untuk menyimpan posisi belakang antrian
    int max = 5;          ///< variable private max untuk menyimpan ukuran maximum antrian
    int queue_array[5];   ///< variable private queue_array untuk menyimpan elemen antrian

public:
    /**
     * @brief Construct a new Queues object
     * set default queues null
     * with front = -1 and rear = -1
     */
    Queues() {
        FRONT = -1;
        REAR  = -1;
    }

    /**
     * @brief method untuk memasukkan data dalam antrian
     * data dimasukkan dalam variable queue_array
     */
    void insert() {
        int num; ///< variable num untuk menyimpan nilai
        cout << "Enter a number: ";
        cin  >> num;
        cout << endl;

        // Cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
            cout << "\nQueue overflow\n";
            return;
        }

        // Cek apakah antrian kosong
        if (FRONT == -1) {
            FRONT = 0;
            REAR  = 0;
        }
        else {
            // Jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1) {
                REAR = 0;
            }
            else {
                REAR = REAR + 1;
            }
        }

        // Assign nilai setelah posisi REAR ditentukan
        queue_array[REAR] = num;
    }

    /**
     * @brief method untuk menghapus data dari antrian
     * data dihapuskan dari dalam variable queue_array
     */
    void remove() {
        // Cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "\nQueue underflow\n";
            return;
        }

        cout << "The element deleted from the queue is: " << queue_array[FRONT] << endl;

        // Cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR) {
            FRONT = -1;
            REAR  = -1;
        }

        // Jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
        else if (FRONT == max - 1) {
            FRONT = 0;
        }

        else {
            FRONT++;
        }
    }

    /**
     * @brief method untuk menampilkan data dalam antrian
     * data ditampilan yang berada dalam variable queue_array
     */
    void display() {
        int FRONT_position = FRONT; ///< variable front_position untuk menandakan posisi element pertama pada variable front
        int REAR_position  = REAR;  ///< variable rear_position untuk menandakan posisi element terakhir pada variable rear

        // Cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        // Jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position) {
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
        else {
            // Jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array
            while (FRONT_position <= max - 1) {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }

            FRONT_position = 0;

            // Iterasi dari awal array hingga REAR
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }

            cout << endl;
        }
    }

}; // ← TUTUP CLASS DI SINI

/**
 * @brief method utama untuk menjalankan program
 * @return int
 */
int main() {
    Queues q; ///< objek untuk menggunakan member yang ada pada class queues
    char ch;  ///< variable ch untuk menyimpan pilihan pada menu yang diberikan

    while (true) {
        try {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;

            switch (ch) {
                case '1':
                    q.insert();
                    break;
                case '2':
                    q.remove();
                    break;
                case '3':
                    q.display();
                    break;
                case '4':
                    return 0;
                default:
                    cout << "Invalid option!!" << endl;
                    break;
            }
        }
        catch (exception& e) {
            cout << "Check for the values entered." << endl;
        }
    }

    return 0;
}