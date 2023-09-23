#include <iostream>
#include <string>

// Интерфейс Notification
class Notification {
public:
    virtual void send(const std::string& title, const std::string& message) = 0;
};

// Класс EmailNotification
class EmailNotification {
private:
    std::string adminEmail;

public:
    EmailNotification(const std::string& adminEmail) : adminEmail(adminEmail) {}

    void sendEmail(const std::string& title, const std::string& message) {
        // Здесь вы можете добавить код для отправки электронной почты
        // В данном примере просто выводим сообщение на экран
        std::cout << "Sent email with title '" << title << "' to '" << adminEmail << "' that says '" << message << "'.\n";
    }
};

// Адаптер для Slack
class SlackNotificationAdapter : public Notification {
private:
    std::string login;
    std::string apiKey;
    std::string chatId;

public:
    SlackNotificationAdapter(const std::string& login, const std::string& apiKey, const std::string& chatId)
        : login(login), apiKey(apiKey), chatId(chatId) {}

    void send(const std::string& title, const std::string& message) override {
        // Здесь добавьте код для отправки уведомления в Slack
        // Используйте значения login, apiKey и chatId для аутентификации и отправки сообщения
        std::cout << "Sent Slack notification with title '" << title << "' to chat '" << chatId << "' that says '" << message << "'.\n";
    }
};

// Адаптер для SMS
class SMSNotificationAdapter : public Notification {
private:
    std::string phone;
    std::string sender;

public:
    SMSNotificationAdapter(const std::string& phone, const std::string& sender)
        : phone(phone), sender(sender) {}

    void send(const std::string& title, const std::string& message) override {
        // Здесь добавьте код для отправки SMS-уведомления
        // Используйте значения phone и sender для отправки SMS
        std::cout << "Sent SMS notification to '" << phone << "' from sender '" << sender << "' that says '" << message << "'.\n";
    }
};

int main() {
    // Пример использования EmailNotification
    EmailNotification emailNotifier("admin@example.com");
    emailNotifier.sendEmail("Test Email", "This is a test email message");

    // Пример использования SlackNotificationAdapter
    SlackNotificationAdapter slackAdapter("slack_login", "slack_api_key", "slack_chat_id");
    slackAdapter.send("Test Slack", "This is a test Slack message");

    // Пример использования SMSNotificationAdapter
    SMSNotificationAdapter smsAdapter("+123456789", "MySender");
    smsAdapter.send("Test SMS", "This is a test SMS message");

    return 0;
}
