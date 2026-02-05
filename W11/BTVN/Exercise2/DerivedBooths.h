#ifndef DERIVED_BOOTHS_H
#define DERIVED_BOOTHS_H

#include "Booth.h"

class FoodBooth : public Booth {
private:
  long long coldStorageFee;

public:
  FoodBooth(string id, double area, double baseRate, long long coldFee)
      : Booth(id, area, baseRate), coldStorageFee(coldFee) {}

  long long calculateRent() const override {
    return getBaseRent() + coldStorageFee;
  }
  string toString() const override;
};

class ClothesBooth : public Booth {
public:
  ClothesBooth(string id, double area, double baseRate)
      : Booth(id, area, baseRate) {}

  long long calculateRent() const override { return getBaseRent(); }
  string toString() const override;
};

class JewelryBooth : public Booth {
private:
  long long securityFee;

public:
  JewelryBooth(string id, double area, double baseRate, long long secFee)
      : Booth(id, area, baseRate), securityFee(secFee) {}

  long long calculateRent() const override {
    return getBaseRent() + securityFee;
  }
  string toString() const override;
};

#endif