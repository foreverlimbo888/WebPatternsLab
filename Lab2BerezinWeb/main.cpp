#include <iostream>
#include <string>

class SocialNetwork {
public:
    virtual void login(std::string username, std::string password) = 0;
    virtual void post(std::string message) = 0;
    virtual ~SocialNetwork() {}
};

class Facebook : public SocialNetwork {
public:
    void login(std::string username, std::string password) override {
        std::cout << "Logged into Facebook with username: " << username << " and password: " << password << std::endl;
    }

    void post(std::string message) override {
        std::cout << "Posted on Facebook: " << message << std::endl;
    }
};

class LinkedIn : public SocialNetwork {
public:
    void login(std::string email, std::string password) override {
        std::cout << "Logged into LinkedIn with email: " << email << " and password: " << password << std::endl;
    }

    void post(std::string message) override {
        std::cout << "Posted on LinkedIn: " << message << std::endl;
    }
};

class SocialNetworkFactory {
public:
    virtual SocialNetwork* createSocialNetwork() = 0;
    virtual ~SocialNetworkFactory() {}
};

class FacebookFactory : public SocialNetworkFactory {
public:
    SocialNetwork* createSocialNetwork() override {
        return new Facebook();
    }
};

class LinkedInFactory : public SocialNetworkFactory {
public:
    SocialNetwork* createSocialNetwork() override {
        return new LinkedIn();
    }
};
