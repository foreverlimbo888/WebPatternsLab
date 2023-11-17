#include <iostream>
#include <unordered_map>

// Інтерфейс для завантаження файлів
class Downloader {
public:
    virtual void download(const std::string& url) = 0;
    virtual ~Downloader() = default;
};

// Реалізація інтерфейсу Downloader
class SimpleDownloader : public Downloader {
public:
    void download(const std::string& url) override {
        // Реалізація завантаження файлів
        std::cout << "Downloading file from: " << url << std::endl;
    }
};

// Клас ProxyDownloader, який виступає в ролі замісника та додає кешування
class ProxyDownloader : public Downloader {
private:
    SimpleDownloader* simpleDownloader;
    std::unordered_map<std::string, std::string> cache;

public:
    ProxyDownloader(SimpleDownloader* downloader) : simpleDownloader(downloader) {}

    void download(const std::string& url) override {
        // Перевірка кешу
        if (cache.find(url) != cache.end()) {
            std::cout << "Retrieving file from cache: " << url << std::endl;
        } else {
            // Якщо не в кеші, використовуємо реальний об'єкт SimpleDownloader
            simpleDownloader->download(url);
            cache[url] = "Cached Content"; // Зберігаємо в кеш
        }
    }
};

int main() {
    // Створення реального об'єкту SimpleDownloader
    SimpleDownloader realDownloader;

    // Створення замісника ProxyDownloader
    ProxyDownloader proxyDownloader(&realDownloader);

    // Клієнтський код використовує ProxyDownloader, але не має знати про кешування
    proxyDownloader.download("https://example.com/file1.txt");
    proxyDownloader.download("https://example.com/file2.txt");
    proxyDownloader.download("https://example.com/file1.txt"); // Використовує кеш

    return 0;
}
