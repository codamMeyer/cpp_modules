#ifndef IODEVICE_H
#define IODEVICE_H

#include <sstream>
#include <string>

class IODevice
{
public:
  virtual std::string readInputLine() = 0;
  virtual void writeOutputLine(const std::string &str) = 0;
};

class MockIODevice : public IODevice
{
public:
  MockIODevice();
  std::string readInputLine();
  void writeOutputLine(const std::string &str);

  void setNextInput(const std::string &input, int index);
  void resetOutput();
  std::string getOutput() const;
  
private:
  std::ostringstream os;
  std::string inputs[5];
  int nextInputToRead;
  const int maxInputIndex;
};

class STDIODevice : public IODevice
{
public:
  std::string readInputLine();
  void writeOutputLine(const std::string &str);
};

#endif