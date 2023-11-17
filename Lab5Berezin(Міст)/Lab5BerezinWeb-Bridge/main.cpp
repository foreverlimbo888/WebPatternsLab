#include <iostream>
#include <string>

// Базовий клас для подання сторінок
class Renderer {
public:
    virtual void renderPage(const std::string& title, const std::string& content) = 0;
    virtual void renderProduct(const std::string& productName, const std::string& description, const std::string& image, int productId) = 0;
    virtual ~Renderer() = default;
};

// Конкретний клас HTMLRenderer, який реалізує подання у форматі HTML
class HTMLRenderer : public Renderer {
public:
    void renderPage(const std::string& title, const std::string& content) override {
        // Рендеринг HTML сторінки
    }

    void renderProduct(const std::string& productName, const std::string& description, const std::string& image, int productId) override {
        // Рендеринг HTML товару
    }
};

// Конкретний клас JsonRenderer, який реалізує подання у форматі JSON
class JsonRenderer : public Renderer {
public:
    void renderPage(const std::string& title, const std::string& content) override {
        // Рендеринг JSON сторінки
    }

    void renderProduct(const std::string& productName, const std::string& description, const std::string& image, int productId) override {
        // Рендеринг JSON товару
    }
};

// Конкретний клас XmlRenderer, який реалізує подання у форматі XML
class XmlRenderer : public Renderer {
public:
    void renderPage(const std::string& title, const std::string& content) override {
        // Рендеринг XML сторінки
    }

    void renderProduct(const std::string& productName, const std::string& description, const std::string& image, int productId) override {
        // Рендеринг XML товару
    }
};

// Базовий клас для сторінок
class Page {
protected:
    Renderer* renderer;

public:
    Page(Renderer* renderer) : renderer(renderer) {}

    virtual void render() = 0;
    virtual ~Page() = default;
};

// Конкретний клас SimplePage, який реалізує просту сторінку
class SimplePage : public Page {
private:
    std::string title;
    std::string content;

public:
    SimplePage(Renderer* renderer, const std::string& title, const std::string& content)
        : Page(renderer), title(title), content(content) {}

    void render() override {
        renderer->renderPage(title, content);
    }
};

// Конкретний клас ProductPage, який реалізує сторінку товару
class Product {
public:
    std::string productName;
    std::string description;
    std::string image;
    int productId;
};

class ProductPage : public Page {
private:
    Product product;

public:
    ProductPage(Renderer* renderer, const Product& product)
        : Page(renderer), product(product) {}

    void render() override {
        renderer->renderProduct(product.productName, product.description, product.image, product.productId);
    }
};

int main() {
    HTMLRenderer htmlRenderer;
    JsonRenderer jsonRenderer;
    XmlRenderer xmlRenderer;

    // Рендеринг простої сторінки у різних форматах
    SimplePage simplePage(&htmlRenderer, "Simple HTML Page", "Hello, this is a simple HTML page.");
    simplePage.render();

    SimplePage simplePageJson(&jsonRenderer, "Simple JSON Page", "Hello, this is a simple JSON page.");
    simplePageJson.render();

    SimplePage simplePageXml(&xmlRenderer, "Simple XML Page", "Hello, this is a simple XML page.");
    simplePageXml.render();

    // Рендеринг сторінки товару у різних форматах
    Product product = {"Laptop", "Powerful laptop with high-resolution display", "laptop.jpg", 12345};
    ProductPage productPage(&htmlRenderer, product);
    productPage.render();

    ProductPage productPageJson(&jsonRenderer, product);
    productPageJson.render();

    ProductPage productPageXml(&xmlRenderer, product);
    productPageXml.render();

    return 0;
}

