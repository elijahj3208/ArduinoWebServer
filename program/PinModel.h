
class PinModel
{
  public :

  PinModel();
  int getPin();
  int getLevel();

  void setPinNum(int pin);
  void setLevelState(int level);

  private :

  int _Pin;
  int _Level;
};

PinModel::PinModel(){}

int PinModel::getPin()
{
  return _Pin;
}

int PinModel::getLevel()
{
  return _Level;
}

void PinModel::setPinNum(int pin)
{
  _Pin = pin;
}

void PinModel::setLevelState(int level)
{
  _Level = level;
}
