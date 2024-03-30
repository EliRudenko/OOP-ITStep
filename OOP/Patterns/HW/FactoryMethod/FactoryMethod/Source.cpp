#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Figure 
{
protected:
    int geometry[4][4]; // ��������� ������
    int color[3]; // ���� ������ (RGB)
    string name; // ��� ������

public:
    virtual ~Figure() {}

    virtual void display() const = 0; // ����� ����������� ����� ��� ����������� ������
};

// ���������� ������ �����

class Square : public Figure 
{
public:
    Square() 
    {
        int geo[4][4] = 
        {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0} 
        };
        memcpy(geometry, geo, sizeof(geometry));

        // ����������
        color[0] = 128;
        color[1] = 0;
        color[2] = 128;

        name = "Square";
    }

    // ��������������� ������ ����������� ������
    void display() const override 
    {
        cout << "Figure: " << name << endl;
        cout << "Geometry:" << endl;
        for (int i = 0; i < 4; ++i) 
        {
            for (int j = 0; j < 4; ++j) 
            {
                //����!!!!!
                if (geometry[i][j] == 1)
                    cout << "\033[38;2;" << color[0] << ";" << color[1] << ";" << color[2] << "m" << geometry[i][j] << "\033[0m ";
                else
                    cout << geometry[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class IShape : public Figure 
{
public:
    IShape() 
    {
        int geo[4][4] = 
        {
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {1, 0, 0, 0} 
        };
        memcpy(geometry, geo, sizeof(geometry));

        // �������
        color[0] = 0;
        color[1] = 255;
        color[2] = 0;

        name = "I Shape";
    }

    // ��������������� ������ ����������� ������
    void display() const override 
    {
        cout << "Figure: " << name << endl;
        cout << "Geometry:" << endl;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j) 
            {
                //����!!!!
                if (geometry[i][j] == 1)
                    cout << "\033[38;2;" << color[0] << ";" << color[1] << ";" << color[2] << "m" << geometry[i][j] << "\033[0m ";
                else
                    cout << geometry[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class SShape : public Figure 
{
public:
    SShape() 
    {
        int geo[4][4] = 
        {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0} 
        };
        memcpy(geometry, geo, sizeof(geometry));

        // �����
        color[0] = 0;
        color[1] = 0;
        color[2] = 255;

        name = "S Shape";
    }

    // ��������������� ������ ����������� ������
    void display() const override 
    {
        cout << "Figure: " << name << endl;
        cout << "Geometry:" << endl;
        for (int i = 0; i < 4; ++i) 
        {
            for (int j = 0; j < 4; ++j) 
            {
                //����!!!
                if (geometry[i][j] == 1)
                    cout << "\033[38;2;" << color[0] << ";" << color[1] << ";" << color[2] << "m" << geometry[i][j] << "\033[0m ";
                else
                    cout << geometry[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class LShape : public Figure 
{
public:
    LShape() 
    {
        int geo[4][4] = 
        {
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0} 
        };
        memcpy(geometry, geo, sizeof(geometry));

        // ���������
        color[0] = 255;
        color[1] = 165;
        color[2] = 0;

        name = "L Shape";
    }

    // ��������������� ������ ����������� ������
    void display() const override 
    {
        cout << "Figure: " << name << endl;
        cout << "Geometry:" << endl;
        for (int i = 0; i < 4; ++i) 
        {
            for (int j = 0; j < 4; ++j) 
            {
                //����!!!!
                if (geometry[i][j] == 1)
                    cout << "\033[38;2;" << color[0] << ";" << color[1] << ";" << color[2] << "m" << geometry[i][j] << "\033[0m ";
                else
                    cout << geometry[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class ZShape : public Figure 
{
public:
    ZShape() 
    {
        int geo[4][4] = 
        {
            {0, 0, 0, 0},
            {1, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0} 
        };
        memcpy(geometry, geo, sizeof(geometry));

        // �������
        color[0] = 255;
        color[1] = 0;
        color[2] = 0;

        name = "* Shape";
    }

    // ��������������� ������ ����������� ������
    void display() const override 
    {
        cout << "Figure: " << name << endl;
        cout << "Geometry:" << endl;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (geometry[i][j] == 1)
                    cout << "\033[38;2;" << color[0] << ";" << color[1] << ";" << color[2] << "m" << geometry[i][j] << "\033[0m ";
                else
                    cout << geometry[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class JShape : public Figure 
{
public:
    JShape() 
    {
        int geo[4][4] = 
        {
            {0, 0, 0, 1},
            {0, 0, 0, 1},
            {0, 0, 1, 1},
            {0, 0, 0, 0} 
        };
        memcpy(geometry, geo, sizeof(geometry));

        // ������
        color[0] = 255;
        color[1] = 255;
        color[2] = 0;

        name = "J Shape";
    }

    // ��������������� ������ ����������� ������
    void display() const override 
    {
        cout << "Figure: " << name << endl;
        cout << "Geometry:" << endl;
        for (int i = 0; i < 4; ++i) 
        {
            for (int j = 0; j < 4; ++j) 
            {
                if (geometry[i][j] == 1)
                    cout << "\033[38;2;" << color[0] << ";" << color[1] << ";" << color[2] << "m" << geometry[i][j] << "\033[0m ";
                else
                    cout << geometry[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class TShape : public Figure 
{
public:
    TShape() 
    {
        int geo[4][4] = 
        {
            {0, 0, 0, 0},
            {0, 1, 1, 1},
            {0, 0, 1, 0},
            {0, 0, 0, 0} 
        };
        memcpy(geometry, geo, sizeof(geometry));

        // ����������
        color[0] = 139;
        color[1] = 69;
        color[2] = 19;

        name = "T Shape";
    }

    // ��������������� ������ ����������� ������
    void display() const override 
    {
        cout << "Figure: " << name << endl;
        cout << "Geometry:" << endl;
        for (int i = 0; i < 4; ++i) 
        {
            for (int j = 0; j < 4; ++j) 
            {
                if (geometry[i][j] == 1)
                    cout << "\033[38;2;" << color[0] << ";" << color[1] << ";" << color[2] << "m" << geometry[i][j] << "\033[0m ";
                else
                    cout << geometry[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// ����������� ����� ��������� �����

class FigureCreator 
{
public:
    virtual Figure* createFigure() = 0;
};



// ���������� ������ ���������� �����

class SquareCreator : public FigureCreator 
{
public:
    Figure* createFigure() override { return new Square(); }
};

class IShapeCreator : public FigureCreator 
{
public:
    Figure* createFigure() override { return new IShape(); }
};

class SShapeCreator : public FigureCreator 
{
public:
    Figure* createFigure() override { return new SShape(); }
};

class ZShapeCreator : public FigureCreator 
{
public:
    Figure* createFigure() override { return new ZShape(); }
};

class LShapeCreator : public FigureCreator 
{
public:
    Figure* createFigure() override { return new LShape(); }
};

class JShapeCreator : public FigureCreator 
{
public:
    Figure* createFigure() override { return new JShape(); }
};

class TShapeCreator : public FigureCreator 
{
public:
    Figure* createFigure() override { return new TShape(); }
};



int main() 
{
    vector<Figure*> figures; // ������� ������ �����


    // ������� ���������� ��� ������ ������
    SquareCreator squareCreator;
    IShapeCreator iShapeCreator;
    SShapeCreator sShapeCreator;
    ZShapeCreator zShapeCreator;
    LShapeCreator lShapeCreator;
    JShapeCreator jShapeCreator;
    TShapeCreator tShapeCreator;


    // ������� ������ � ��������� �� � ������
    figures.push_back(squareCreator.createFigure());
    figures.push_back(iShapeCreator.createFigure());
    figures.push_back(sShapeCreator.createFigure());
    figures.push_back(zShapeCreator.createFigure());
    figures.push_back(lShapeCreator.createFigure());
    figures.push_back(jShapeCreator.createFigure());
    figures.push_back(tShapeCreator.createFigure());

    // ���������� ��� ������ � �������
    for (Figure* figure : figures) 
    {
        figure->display();
        cout << endl;
    }

    // ����������� ���������� ������
    for (Figure* figure : figures) { delete figure; }

    // ������� ����� ����� ����������� ���������, ������ ��� ��� ����� � ���� ������ �� ����������� ���� ����� ��
    cout << "Press Enter to exit...";
    cin.get();

    return 0;
}


