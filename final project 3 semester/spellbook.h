class Spells_level_1 // заклинания первого уровня
{
public:
    Spells_level_1(const std::string& s) { std::cout << "Creating " << s << std::endl; } // Отчет о созании заклинания
    virtual ~Spells_level_1() {};                                                        // деструктор
    virtual std::string cast_level_1() const = 0;                                        // Отчет о вызове заклинания
};

class Expelliarmus : public Spells_level_1 // Атакующее заклинание первого уровня
{
public:
    Expelliarmus() : Spells_level_1( "Expelliarmus" ) {}
    std::string cast_level_1() const override // Гарантированное переопределение
    {
        return "Expelliarmus";
    }
};

class Protego : public Spells_level_1 // Защитное заклинание первого уровня
{
public:
    Protego() : Spells_level_1("Protego") {}
    std::string cast_level_1() const override
    {
        return "Protego";
    }
};

class Wingardium_Leviosa : public Spells_level_1 // Бытовое заклинание первого уровня
{
public:
    Wingardium_Leviosa() : Spells_level_1("Wingardium_Leviosa") {}
    std::string cast_level_1() const override
    {
        return "Wingardium_Leviosa";
    }
};

class Crucio : public Spells_level_1 // Непростительное заклинание первого уровня
{
public:
    Crucio() : Spells_level_1("Crucio") {}
    std::string cast_level_1() const override
    {
        return "Crucio";
    }
};


class Spells_level_2 // заклинания второго уровня
{
public:
    Spells_level_2(const std::string& s) { std::cout << "Creating " << s << std::endl; } // Отчет о созании заклинания
    virtual ~Spells_level_2() {};                                                        // деструктор
    virtual std::string cast_level_2() const = 0;                                        // Отчет о вызове заклинания
};

class Bombarda : public Spells_level_2 // Атакующее заклинание второго уровня
{
public:
    Bombarda() : Spells_level_2("Bombarda") {}
    std::string cast_level_2() const override 
    {
        return "Bombarda";
    }
};

class Protego_Diabolica : public Spells_level_2 // Защитное заклинание второго уровня
{
public:
    Protego_Diabolica() : Spells_level_2("Protego_Diabolica") {}
    std::string cast_level_2() const override 
    {
        return "Protego_Diabolica";
    }
};

class Lumos : public Spells_level_2 // Повседневное заклинание второго уровня
{
public:
    Lumos() : Spells_level_2("Lumos") {}
    std::string cast_level_2() const override 
    {
        return "Lumos";
    }
};

class Imperio : public Spells_level_2 // Непростительное заклинание второго уровня
{
public:
    Imperio() : Spells_level_2("Imperio") {}
    std::string cast_level_2() const override 
    {
        return "Imperio";
    }
};


class Spells_level_3 // заклинания третьего уровня
{
public:
    Spells_level_3(const std::string& s) { std::cout << "Creating " << s << std::endl; } // Отчет о созании заклинания
    virtual ~Spells_level_3() {};                                                        // деструктор
    virtual std::string cast_level_3() const = 0;                                        // Отчет о вызове заклинания
};

class Riddikulus : public Spells_level_3 // Атакующее заклинание третьего уровня
{
public:
    Riddikulus() : Spells_level_3("Riddikulus") {}
    std::string cast_level_3() const override 
    {
        return "Riddikulus";
    }
};

class Expecto_Patronum : public Spells_level_3 // Защитное заклинание третьего уровня
{
public:
    Expecto_Patronum() : Spells_level_3("Expecto_Patronum") {}
    std::string cast_level_3() const override 
    {
        return "Expecto_Patronum";
    }
};

class Nox : public Spells_level_3 // Повседневное заклинание третьего уровня
{
public:
    Nox() : Spells_level_3("Nox") {}
    std::string cast_level_3() const override 
    {
        return "Nox";
    }
};

class Avada_Kedavra : public Spells_level_3 // Непростительное заклинание третьего уровня
{
public:
    Avada_Kedavra() : Spells_level_3("Avada_Kedavra") {}
    std::string cast_level_3() const override 
    {
        return "Avada_Kedavra";
    }
};


class SpellBuilder 
{
public:
    virtual ~SpellBuilder() {}

    ///методы для заклинаний каждого уровня
    virtual void buildLevel1Spell() = 0;
    virtual void buildLevel2Spell() = 0;
    virtual void buildLevel3Spell() = 0;

    virtual Spells_level_1* getLevel1Spell() = 0;
    virtual Spells_level_2* getLevel2Spell() = 0;
    virtual Spells_level_3* getLevel3Spell() = 0;
};

// Конкретный строитель для создания атакующих заклинаний
class AttackSpellBuilder : public SpellBuilder {
private:
    Spells_level_1* spell1;
    Spells_level_2* spell2;
    Spells_level_3* spell3;

public:
    AttackSpellBuilder() : spell1(nullptr), spell2(nullptr), spell3(nullptr) {}

    void buildLevel1Spell() override {
        spell1 = new Expelliarmus();
    }

    void buildLevel2Spell() override {
        spell2 = new Bombarda();
    }

    void buildLevel3Spell() override {
        spell3 = new Riddikulus();
    }

    Spells_level_1* getLevel1Spell() override {
        return spell1;
    }

    Spells_level_2* getLevel2Spell() override {
        return spell2;
    }

    Spells_level_3* getLevel3Spell() override {
        return spell3;
    }

    ~AttackSpellBuilder() {
        delete spell1;
        delete spell2;
        delete spell3;
    }
};


// Конкретный строитель для защитных заклинаний
class ProtectionSpellBuilder : public SpellBuilder {
private:
    Spells_level_1* spell1;
    Spells_level_2* spell2;
    Spells_level_3* spell3;

public:
    ProtectionSpellBuilder() : spell1(nullptr), spell2(nullptr), spell3(nullptr) {}

    void buildLevel1Spell() override {
        spell1 = new Protego();
    }

    void buildLevel2Spell() override {
        spell2 = new Protego_Diabolica();
    }

    void buildLevel3Spell() override {
        spell3 = new Expecto_Patronum();
    }

    Spells_level_1* getLevel1Spell() override {
        return spell1;
    }

    Spells_level_2* getLevel2Spell() override {
        return spell2;
    }

    Spells_level_3* getLevel3Spell() override {
        return spell3;
    }

    ~ProtectionSpellBuilder() {
        delete spell1;
        delete spell2;
        delete spell3;
    }
};

// Конкретный строитель для повседневных заклинаний
class CasualSpellBuilder : public SpellBuilder {
private:
    Spells_level_1* spell1;
    Spells_level_2* spell2;
    Spells_level_3* spell3;

public:
    CasualSpellBuilder() : spell1(nullptr), spell2(nullptr), spell3(nullptr) {}

    void buildLevel1Spell() override {
        spell1 = new Wingardium_Leviosa();
    }

    void buildLevel2Spell() override {
        spell2 = new Lumos();
    }

    void buildLevel3Spell() override {
        spell3 = new Nox();
    }

    Spells_level_1* getLevel1Spell() override {
        return spell1;
    }

    Spells_level_2* getLevel2Spell() override {
        return spell2;
    }

    Spells_level_3* getLevel3Spell() override {
        return spell3;
    }

    ~CasualSpellBuilder() {
        delete spell1;
        delete spell2;
        delete spell3;
    }
};

// Конкретный строитель для непростительных заклинаний
class UnforgivableSpellBuilder : public SpellBuilder {
private:
    Spells_level_1* spell1;
    Spells_level_2* spell2;
    Spells_level_3* spell3;

public:
    UnforgivableSpellBuilder() : spell1(nullptr), spell2(nullptr), spell3(nullptr) {}

    void buildLevel1Spell() override {
        spell1 = new Crucio();
    }

    void buildLevel2Spell() override {
        spell2 = new Imperio();
    }

    void buildLevel3Spell() override {
        spell3 = new Avada_Kedavra();
    }

    Spells_level_1* getLevel1Spell() override {
        return spell1;
    }

    Spells_level_2* getLevel2Spell() override {
        return spell2;
    }

    Spells_level_3* getLevel3Spell() override {
        return spell3;
    }

    ~UnforgivableSpellBuilder() {
        delete spell1;
        delete spell2;
        delete spell3;
    }
};

// Менеджер, использующий строитель для создания заклинаний
class SpellDirector {
public:
    void createAttackSpells(SpellBuilder& builder) {
        builder.buildLevel1Spell();
        builder.buildLevel2Spell();
        builder.buildLevel3Spell();
    }

    void createProtectionSpells(SpellBuilder& builder) {
        builder.buildLevel1Spell();
        builder.buildLevel2Spell();
        builder.buildLevel3Spell();
    }

    void createCasualSpells(SpellBuilder& builder) {
        builder.buildLevel1Spell();
        builder.buildLevel2Spell();
        builder.buildLevel3Spell();
    }

    void createUnforgivableSpells(SpellBuilder& builder) {
        builder.buildLevel1Spell();
        builder.buildLevel2Spell();
        builder.buildLevel3Spell();
    }
};