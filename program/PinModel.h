class PinModel
{
  public :

  PinModel(int pin, int level);
  int GetPin();
  int GetLevel();

  private :

  int _Pin;
  int _Level;
};

PinModel::PinModel(int pin, int level)
{
  _Pin = pin;
  _Level = level;  
}

int PinModel::GetPin()
{
  return _Pin;
}

int PinModel::GetLevel()
{
  return _Level;
}
