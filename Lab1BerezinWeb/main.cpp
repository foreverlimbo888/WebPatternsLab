#include <iostream>
#include <string>

class Database {
    private:
        static Database* instance;
        std::string storageType; //(локальный диск или Amazon S3)

        Database() {}

    public:
        static Database* getInstance() {
            if (!instance) {
                instance = new Database();
            }
            return instance;
        }

        void setStorageType(const std::string& type) {
            storageType = type;
        }

        void saveFile(const std::string& filename) {
            std::cout << "Saved to " << storageType << ": " << filename << std::endl;
        }

        void retrieveFile(const std::string& filename) {
            std::cout << "Retrieved from " << storageType << ": " << filename << std::endl;
        }
};

Database* Database::instance = nullptr;

int main() {
    Database* db = Database::getInstance();

    db->setStorageType("Local Disk");

    db->saveFile("file1.txt");
    db->retrieveFile("file2.txt");

    return 0;
}
