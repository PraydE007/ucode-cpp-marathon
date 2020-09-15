#ifndef WALLETMANAGER_H_
#define WALLETMANAGER_H_

#include <iostream>

struct Wallet {
    int septims;
};

Wallet* createWallet(int septims);
void destroyWallet(Wallet* wallet);

Wallet* createWallets(int amount);
void destroyWallets(Wallet* wallets);

#endif // WALLETMANAGER_H_
