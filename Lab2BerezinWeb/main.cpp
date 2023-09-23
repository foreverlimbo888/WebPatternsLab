#include <iostream>
#include <string>

class PostgreSQL {
};

class MySQL {
};

class Builder {
public:
    virtual void select() = 0;
    virtual void where() = 0;
    virtual void limit() = 0;
    virtual void getSQL() = 0;
};

class PostgreSQLBuilder : public Builder {
private:
    PostgreSQL postgres;

public:
    void select() {
        postgres = PostgreSQL();
    }

    void where() {
    }

    void limit() {
    }

    void getSQL() {
    }

    PostgreSQL getResult() {
        return postgres;
    }
};

class MySQLBuilder : public Builder {
private:
    MySQL mysql;

public:
    void select() {
        mysql = MySQL();
    }

    void where() {
    }

    void limit() {
    }

    void getSQL() {
    }

    MySQL getResult() {
        return mysql;
    }
};

class Director {
public:
    void constructDataBase(Builder& builder) {
        builder.select();
        builder.where();
        builder.limit();
        builder.getSQL();
    }
};

class Application {
public:
    void makePostgreSQL() {
        Director director;
        PostgreSQLBuilder builder;
        director.constructDataBase(builder);
        PostgreSQL postgres = builder.getResult();
    }

    void makeMySQL() {
        Director director;
        MySQLBuilder builder;
        director.constructDataBase(builder);
        MySQL mysql = builder.getResult();
    }
};
