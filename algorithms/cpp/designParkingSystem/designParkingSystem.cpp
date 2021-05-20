// Source: https://leetcode.com/problems/design-parking-system/
// Author: Miao Zhang
// Date:   2021-05-20

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) : big_(big), medium_(medium), small_(small) {

    }

    bool addCar(int carType) {
        if (carType == 1) {
            if (big_ > 0) {
                big_--;
                return true;
            }
        } else if (carType == 2) {
            if (medium_ > 0) {
                medium_--;
                return true;
            }
        } else {
            if (small_ > 0) {
                small_--;
                return true;
            }
        }
        return false;
    }
private:
    int big_;
    int medium_;
    int small_;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
