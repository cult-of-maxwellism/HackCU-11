//universal functions
ofstream open_file(const string &filepath);
string get_vehicle_number();

//preventative functions
void performPreventative(string carname, string filepath);
void checkStart(string filepath);
void inspectEngine(string filepath);
void checkBattery(string filepath);
void checkFluids(string filepath);
void checkBrakePads(string filepath);
void inspectTires(string filepath);

//diagnostic functions
void diagnostic(string carname, string filepath);
void engine(string filepath);
void transmission(string filepath);
void drivetrain(string filepath);
void bodywork(string filepath);
void EngAcc(string filepath);
void exhaust(string filepath);
void lights(string filepath);
void accessories(string filepath);