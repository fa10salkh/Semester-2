#include <iostream> 
using namespace std;
/// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent;
};
Pohon *root, *baru;
// Inisialisasi
void init()
{
    root = NULL;
}
// Cek Node
int isEmpty()
{
    if (root == NULL)
        return 1; // true
    else
        return 0; // false
}
// Buat Node Baru
void buatNode(char data)
{
    if (isEmpty() == 1)
    {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\n Pohon sudah dibuat" << endl;
    }
}
// Tambah Kiri
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        // cek apakah child kiri ada atau tidak
        if (node->left != NULL)
        {
            // kalau ada
            cout << "\n Node " << node->data << " sudah ada child kiri!"
                 << endl;
            return NULL;
        }
        else
        {
            // kalau tidak ada
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}
// Tambah Kanan
Pohon *insertRight(char data, Pohon *node)
{
    if (root == NULL)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        // cek apakah child kanan ada atau tidak
        if (node->right != NULL)
        {
            // kalau ada
            cout << "\n Node " << node->data << " sudah ada child kanan!"
                 << endl;
            return NULL;
        }
        else
        {
            // kalau tidak ada
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
                return baru;
        }
    }
}
// Ubah Data Tree
void update(char data, Pohon *node)
{
    if (isEmpty() == 1)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\n Node " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}
// Lihat Isi Data Tree
void retrieve(Pohon *node)                                   
{
    if (!root)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\n Data node : " << node->data << endl;
        }
    }
}
// Cari Data Tree
void find(Pohon *node)
{
    if (!root)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\n Data Node : " << node->data << endl;
            cout << " Root : " << root->data << endl;
            if (!node->parent)
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node &&
                node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node &&
                     node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right->data << endl;
        }
    }
}
// Penelurusan (Traversal)
// preorder
void preOrder(Pohon *node = root)
{
    if (!root)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}
// inOrder
void inOrder(Pohon *node = root)
{
    if (!root)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}
// postOrder
void postOrder(Pohon *node = root)
{
    if (!root)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}
// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (!root)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}
// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (!root)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl;
    }
}
// Hapus Tree
void clear()
{
    if (!root)
        cout << "\n Buat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}
// Cek Size Tree
int size(Pohon *node = root)
{
    if (!root)
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}
// Cek Height Level Tree
int height(Pohon *node = root)
{
    if (!root)
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}
// Karakteristik Tree
void charateristic()
{
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}

void tampilkanChild (Pohon *node)
{
    if (node->left != NULL)
    {
        cout << "Child Kiri: " << node->left->data << endl;
    }
    if (node->right != NULL)
    {
        cout << "Child Kanan: " << node->right->data << endl;
    }
}

void tampilkanDescendant (Pohon *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " ";
    tampilkanDescendant(node->left);
    tampilkanDescendant(node->right);
}

Pohon* cariNode (char data, Pohon *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->data == data)
    {
        cout << "Node " << data << " ditemukan.\n";
        return node;
    }
    Pohon* foundNode = cariNode(data, node->left);
    if (foundNode == NULL)
    {
        foundNode == cariNode(data, node->right);
    }
    return foundNode;
}

int main()
{
    int pilihan_Faisal_Khoiruddin_2311102046;
    char data;
    Pohon *node;
    do {
        cout << "\n=================================" << endl;
        cout << "|               Menu            |" << endl;
        cout << "=================================" << endl;
        cout << "| 1  | Buat Node                |" << endl;
        cout << "| 2  | Insert Left              |" << endl;
        cout << "| 3  | insert Right             |" << endl;
        cout << "| 4  | Update Node              |" << endl;
        cout << "| 5  | Retrieve Node            |" << endl;
        cout << "| 6  | Temukan Node             |" << endl;
        cout << "| 7  | Preorder Traversal       |" << endl;
        cout << "| 8  | Inorder Traversal        |" << endl;
        cout << "| 9  | Postorder Traversal      |" << endl;
        cout << "| 10 | Delete Subtree           |" << endl;
        cout << "| 11 | Clear Tree               |" << endl;
        cout << "| 12 | Size of Tree             |" << endl;
        cout << "| 13 | Height of Tree           |" << endl;
        cout << "| 14 | Characteristic of Tree   |" << endl;
        cout << "| 15 | Keluar                   |" << endl;
        cout << "=================================" << endl;
        cout << "Masukkan pilihan : ";
        cin >> pilihan_Faisal_Khoiruddin_2311102046;
        switch (pilihan_Faisal_Khoiruddin_2311102046)
        {
            case 1: 
                cout << "Masukkan data: ";
                cin >> data;
                buatNode(data);
                break;
            case 2:
                cout << "Masukkan data node: ";
                cin >> data;
                node = cariNode(data, root);
                if (node != NULL)
                {
                    cout << "Node ditemukan. Masukkan data child kiri: ";
                    cin >> data;
                    insertLeft(data, node);
                } else {
                    cout << "Node tidak ditemukan,\n";
                }
                break;
            case 3:
                cout << "Masukkan data node: ";
                cin >> data;
                node = cariNode (data, root);
                if (node != NULL)
                {
                    cout << "Node ditemukan. Masukkan data child kanan: ";
                    cin >> data;
                    insertRight(data, node);
                } else {
                    cout << "Node tidak ditemukan.\n";
                }
                break;
            case 4:
                cout << "Masukkan data node: ";
                cin >> data;
                node = cariNode(data, root);
                if (node != NULL)
                {
                    cout << "Node ditemukan. Masukkan data baru: ";
                    cin >> data;
                    update(data, node);
                } else {
                    cout << "Node tidak ditemukan.\n";
                }
                break;
            case 5:
                cout << "Masukkan data node: ";
                cin >> data;
                node = cariNode(data, root);
                retrieve(node);
                break;
            case 6:
                cout << "Masukkan data node: ";
                cin >> data;
                node = cariNode(data, root);
                find(node);
                break;
            case 7:
                cout << "Preorder Traversal: ";
                preOrder(root);
                cout << "\n";
                break;
            case 8:
                cout << "Inorder Traversal: ";
                inOrder(root);
                cout << "\n";
                break;
            case 9:
                cout << "Postorder Traversal: ";
                postOrder(root);
                cout << "\n";
                break;
            case 10:
                cout << "Masukkan data node: ";
                cin >> data;
                node = cariNode(data, root);
                deleteSub(node);
                break;
            case 11:
                clear();
                break;
            case 12:
                cout << "Size if Tree: " << size(root) << "\n";
                break;
            case 13:
                cout << "Height of Tree: " << height(root) << "\n";
                break;
            case 14:
                charateristic();
                break;
            case 15:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";                 
        }

    } while (pilihan_Faisal_Khoiruddin_2311102046 != 0);
    return 0;
}