#include <Trainner.h>
#include <IDataSource.h>
#include <BrainThinker.h>

Trainer::Trainer()
{
    _brain = new BrainThinker();
}
Trainer::~Trainer()
{
	delete _brain;
}
void Trainer::Train(IDataSource*& dataSource, const string& gameName, const string& keyboardType, const string& nnTopology, const string& nnWeigths, const bool& filter)
{
    _brain->TrainNeuronalNetwork(dataSource,gameName, nnTopology, nnWeigths, [gameName,keyboardType,filter](Json& jsonWeigths){
                                                                                                                                jsonWeigths[KEYBOARD] = keyboardType;
                                                                                                                                jsonWeigths[GAME] =  gameName;
                                                                                                                                jsonWeigths[FILTER] =  filter;});
}