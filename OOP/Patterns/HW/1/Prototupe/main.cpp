#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class AbstractDevice 
{
protected:
    string producer;

public:
    string GetProducer() 
    {
        return this->producer;
    }
    void SetProducer(string producer) 
    {
        this->producer = producer;
    }
    virtual AbstractDevice* Clone() = 0;
};

class Box : public AbstractDevice 
{
    string color;
public:
    string GetColor() 
    {
        return this->color;
    }
    void SetColor(string color) 
    {
        this->color = color;
    }
    AbstractDevice* Clone() override 
    {
        Box* box = new Box;
        *box = *this;
        return box;
    }
};

class Memory : public AbstractDevice 
{
    int volume;
    string type;
public:
    string GetType() 
    {
        return this->type;
    }
    void SetType(string type) 
    {
        this->type = type;
    }
    int GetVolume() 
    {
        return this->volume;
    }
    void SetVolume(int volume) 
    {
        this->volume = volume;
    }
    AbstractDevice* Clone() override 
    {
        Memory* memory = new Memory;
        *memory = *this;
        return memory;
    }
};

class Hdd : public AbstractDevice 
{
    int volume;
    string type;
public:
    string GetType() 
    {
        return this->type;
    }
    void SetType(string type) 
    {
        this->type = type;
    }
    int GetVolume() 
    {
        return this->volume;
    }
    void SetVolume(int volume) 
    {
        this->volume = volume;
    }
    AbstractDevice* Clone() override 
    {
        Hdd* hdd = new Hdd;
        *hdd = *this;
        return hdd;
    }
};

class Processor : public AbstractDevice 
{
    int corecount;
    double frequency;
public:
    double GetFrequency() 
    {
        return this->frequency;
    }
    void SetFrequency(double frequency) {
        this->frequency = frequency;
    }
    int GetCoreCount() 
    {
        return this->corecount;
    }
    void SetCoreCount(int corecount) 
    {
        this->corecount = corecount;
    }
    AbstractDevice* Clone() override 
    {
        Processor* processor = new Processor;
        *processor = *this;
        return processor;
    }
};

class VideoCard : public AbstractDevice
{
    int volume;
public:
    int GetVolume() 
    {
        return this->volume;
    }
    void SetVolume(int volume) 
    {
        this->volume = volume;
    }
    AbstractDevice* Clone() override 
    {
        VideoCard* videocard = new VideoCard;
        *videocard = *this;
        return videocard;
    }
};

class Webcam : public AbstractDevice 
{
    int resolution;
public:
    int GetResolution() 
    {
        return this->resolution;
    }
    void SetResolution(int resolution) 
    {
        this->resolution = resolution;
    }
    AbstractDevice* Clone() override 
    {
        Webcam* webcam = new Webcam;
        *webcam = *this;
        return webcam;
    }
};

class Mainboard : public AbstractDevice 
{
    double busfrequency;
    VideoCard* videocard;
public:
    double GetBusFrequency() 
    {
        return this->busfrequency;
    }
    void SetBusFrequency(double busfrequency) 
    {
        this->busfrequency = busfrequency;
    }
    VideoCard* GetVideoCard() 
    {
        return this->videocard;
    }
    void SetVideoCard(VideoCard* videocard) 
    {
        this->videocard = videocard;
    }
    AbstractDevice* Clone() override 
    {
        Mainboard* newObj = new Mainboard;
        *newObj = *this;
        newObj->videocard = this->videocard != nullptr ? (VideoCard*)this->videocard->Clone() : nullptr;
        return newObj;
    }
};

class Laptop : public AbstractDevice 
{
    Mainboard* mainboard;
    Processor* processor;
    Webcam* webcam;
public:
    Laptop(Mainboard* mainboard, Processor* processor, Webcam* webcam)
        : mainboard(mainboard), processor(processor), webcam(webcam) {}

    Mainboard* GetMainboard() 
    {
        return this->mainboard;
    }
    void SetMainboard(Mainboard* mainboard) 
    {
        this->mainboard = mainboard;
    }
    Processor* GetProcessor() 
    {
        return this->processor;
    }
    void SetProcessor(Processor* processor) 
    {
        this->processor = processor;
    }
    Webcam* GetWebcam() 
    {
        return this->webcam;
    }
    void SetWebcam(Webcam* webcam) 
    {
        this->webcam = webcam;
    }
    AbstractDevice* Clone() override 
    {
        Laptop* laptop = new Laptop(
            dynamic_cast<Mainboard*>(this->mainboard->Clone()),
            dynamic_cast<Processor*>(this->processor->Clone()),
            dynamic_cast<Webcam*>(this->webcam->Clone()));
        *laptop = *this;
        return laptop;
    }
};

int main() 
{
    Mainboard* mainboard = new Mainboard();
    mainboard->SetProducer("Asus");
    mainboard->SetBusFrequency(2400);

    Processor* processor = new Processor();
    processor->SetProducer("Intel");
    processor->SetFrequency(3.6);

    Webcam* webcam = new Webcam();
    webcam->SetProducer("Logitech");
    webcam->SetResolution(1080);

    Laptop* prototype = new Laptop(mainboard, processor, webcam);
    AbstractDevice* laptopCopy = prototype->Clone();

    cout << "Laptop Copy Information:" << endl;
    cout << "Mainboard Producer: " << dynamic_cast<Laptop*>(laptopCopy)->GetMainboard()->GetProducer() << endl;
    cout << "Processor Producer: " << dynamic_cast<Laptop*>(laptopCopy)->GetProcessor()->GetProducer() << endl;
    cout << "Webcam Producer: " << dynamic_cast<Laptop*>(laptopCopy)->GetWebcam()->GetProducer() << endl;
    cout << "Webcam Resolution: " << dynamic_cast<Laptop*>(laptopCopy)->GetWebcam()->GetResolution() << "p" << endl;

    return 0;
}
