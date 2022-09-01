#include "Position.h"
#include "Champion.h"
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <random>

#define PI 3.1415

Position::Position()
{
    xm = -1000;
    ym = -1000;
    xcoor = -1000;
    ycoor = -1000;
    /*Map = new std::vector<std::vector<int>>;
    for(int i = 0; i < MapWidth; i++){
        std::vector<int> vect(MapLength);
        Map->push_back(vect);
    }
*/
    /*int i = 0;
    if(i == 0){
        std::cout << "bonjour 1" << std::endl;
    }
    i++;*/
  
    std::cout << "bonjour 1" << std::endl;
    Map = new std::vector<std::vector<Champion*>>;
    std::cout << "hello denis" << std::endl;
    for(int i = 0; i < MapWidth; i++){
        std::vector<Champion*> vect;
        for(int j = 0; j < MapLength; j++){
            Champion* Champ = new Champion(Map);
            Champ->SetChampionName("Empty");
            vect.push_back(Champ);
        }
        Map->push_back(vect);
    }
    std::cout << "bonjour 2" << std::endl;
};

Position::Position(std::vector<std::vector<Champion*>>* DefineMap){
    Map = DefineMap;
};

void Position::SetInitialPosition(Champion* Champ, int x, int y){
    if( x >= 0 && y >= 0 && x < MapWidth && y < MapLength && ((*Map)[x][y])->GetChampionName() == "Empty"){
        ((*Map)[x][y]) = Champ; 
        xm = x;
        ym = y;
        xcoor = Computexcoor();
        ycoor = Computeycoor();
    }
    else if(x < 0 || y < 0 || x >= MapWidth || y >= MapWidth){
        xm = -1000;
        ym = -1000;
        xcoor = -1000;
        ycoor = -1000;
    }
    else{
        std::cout << "Champ has not been added because it is overriding an already initialized champ, check positions" << std::endl;   
    }
}

double Position::Computexcoor(){
    std::cout << std::sin(60) << std::endl;
    return xm*std::sin(PI/3);
}

double Position::Computeycoor(){
    if(xm%2 == 0){
        return ym;
    }
    else{
        return ym + 0.5;
    }
}

int Position::Getxm(){
    return xm;
}

int Position::Getym(){
    return ym;
}

double Position::Getxcoor(){
    return xcoor;
}

double Position::Getycoor(){
    return ycoor;
}

int Position::GetHexDistance(Champion* Champ){
    int hextot = 0;
    int xself = xm;
    int yself = ym;
    int xmbis = Champ->Getxm();
    int ymbis = Champ->Getym();
    if(xself >= 0 && xself < MapWidth && xmbis >= 0 && xmbis < MapWidth && yself >= 0 && yself < MapLength && ymbis >= 0 && ymbis < MapLength){
        while(xself != xmbis || yself != ymbis){
            std::cout << xself << " " <<  yself << "  ->   " << xmbis << " " << ymbis << std::endl;
            if(xself == xmbis){
                hextot+= std::abs(yself-ymbis);
                yself = ymbis;
            }
            else{
                hextot++;
                if(yself > ymbis){
                    if(xself%2 == 0){
                        yself--;
                    }
                }
                else{
                    if(xself%2 == 1){
                        yself++;
                    }
                }
                if(xself > xmbis){
                    xself--;
                }
                else{
                    xself++;
                }
            }
        }
        return hextot;
    }
    else{
        return -1;
    }
}

double Position::GetRealDistance(Champion* Champ){
    return std::sqrt(std::pow((xcoor - Champ->Getxcoor()), 2) + std::pow((ycoor - Champ->Getycoor()), 2));
}

void Position::MoveToFocused(){
    if((*Map)[xm][ym]->CheckFocus()){

    }
}




void Position::PrintLastTopHex(){
    std::cout <<"       *      "; 
    for(int j = 0; j < MapLength -1; j++){
        std::cout <<"       *      ";
    }
    std::cout <<"       *      "; 
    std::cout << std::endl;
    
    std::cout <<"          *   ";
    for(int j = 0; j < MapLength -1; j++){
        std::cout <<"    *     *   ";
    }
    std::cout <<"    *         ";
    std::cout << std::endl;
    
    std::cout <<"             *";
    for(int j = 0; j < MapLength -1; j++){
        std::cout <<" *           *";
    }
    std::cout <<" *             ";
    std::cout << std::endl;
}



void Position::PrintTopHex(int i){
    if(i%2 == 0){
        for(int j = 0; j < MapLength; j++){
            std::cout <<"       *      ";
        }
        if(i != 0){
            std::cout << "       *";
        }
        std::cout << std::endl;
        
        for(int j = 0; j < MapLength; j++){
            std::cout <<"    *     *   ";
        }
        if(i != 0){
            std::cout << "    *";
        }
        std::cout << std::endl;
        
        for(int j = 0; j < MapLength; j++){
            std::cout <<" *           *";
        }
        if(i != 0){
            std::cout << " *";
        }
        std::cout << std::endl;
    }
}

void Position::PrintBottomHex(int i){
    if(i%2 == 0){
        for(int j = 0; j < MapLength; j++){
            std::cout <<" *           *";
        }
            std::cout << " *";
        std::cout << std::endl;
    
        for(int j = 0; j < MapLength; j++){
            std::cout <<"    *     *   ";
        }
            std::cout << "    *";
        std::cout << std::endl;
    
        for(int j = 0; j < MapLength; j++){
            std::cout <<"       *      ";
        }
            std::cout << "       *";
        std::cout << std::endl;   
    }
}

void Position::PrintLateralHex(int i) {
    if(i%2 == 0){
        for(int k = 0; k < 3; k++){
            std::cout << "|" ;
            for(int j = 0; j < MapLength; j++){
                if(k == 1 && (*Map)[i][j]->GetChampionName() != "Empty"){
                        std::cout <<"     " <<  ((*Map)[i][j])->GetColorCode() << ((*Map)[i][j]->GetChampionName()).substr(0,4) << ((*Map)[i][j])->GetReset() << "    |";
                    }
                    else{
                        std::cout <<"             |";
                    }
                }
            std::cout << std::endl;
        }
    }
    else{
        for(int k = 0; k < 3; k++){
            std::cout << "       |" ;
            for(int j = 0; j < MapLength; j++){
                if(k == 1 && (*Map)[i][j]->GetChampionName() != "Empty"){
                    std::cout <<"     " <<  ((*Map)[i][j])->GetColorCode() << ((*Map)[i][j]->GetChampionName()).substr(0,4) << ((*Map)[i][j])->GetReset() << "    |";
                }
                else{
                    std::cout <<"             |";
                }
            }
        std::cout << std::endl;
        }
    }
}

void Position::PrintMap(){
    std::cout << "//////////////////// Current state of the map: ////////////////////" << std::endl;
    for(int i = 0; i < MapWidth; i++){
        PrintTopHex(i);     
        PrintLateralHex(i);
        PrintBottomHex(i); 
        
    }
    PrintLastTopHex();        
}



std::vector<std::vector<Champion*>>* Position::GetMap(){
    return Map;
}

/*std::vector<std::vector<Champion*>>* Position::GetMap2(){
    return Map2;
}*/




Champion* Position::FindClosestInRange(std::mt19937* g){
    std::vector<Champion*> result;
    double min_distance = std::sqrt(std::pow(MapLength,2) + std::pow(MapWidth,2));
    int range = (*Map)[xm][ym]->GetRange();
    int xmin = xm-range;
    if(xmin < 0){
        xmin = 0;
    }
    int xmax = xm+range;
    if(xmax >= MapWidth){
        xmax = MapWidth-1;
    }
    for(int i = xmin; i <= xmax; i++){
        int ydelt;
        int ymin;
        int ymax;
        if((xm - i)%2 == 0){
            ydelt = std::abs(xm-i)/2 +(range - std::abs(xm-i));
            ymin = ym-ydelt;
            ymax = ym+ydelt;
        }
        else{
            if(xm%2 == 1){
                ydelt = (std::abs(xm-i)-1)/2 + (range - std::abs(xm - i));            
                ymin = ym-ydelt;
                ymax = ym+ydelt+1;
            }
            else{
                ydelt = (std::abs(xm-i)+1)/2 + (range - std::abs(xm - i));
                ymin = ym-ydelt;
                ymax = ym+ydelt-1;
            }
        }
        if(ymin < 0){
            ymin = 0;
        }
        if(ymax >= MapLength){
            ymax = MapLength-1;
        }
        for(int j = ymin; j <= ymax; j++){
            Champion* Champ = (*Map)[i][j]; 
            if(Champ->GetChampionName() != "Empty" && (i != xm || j != ym)){
                double real_distance = (*Map)[xm][ym]->GetRealDistance(Champ);
                if(real_distance < min_distance - 0.05){
                    min_distance = real_distance;
                    result.clear();
                    result.push_back(Champ);
                }
                else if(real_distance >= min_distance - 0.05 && real_distance <= min_distance + 0.05){
                    result.push_back(Champ);
                }
            }
        }            
    }
/*    std::cout << min_distance << "  " << result.size() << std::endl;
    for(int i = 0; i < result.size(); i++){
        std::cout << result[i]->GetChampionName() << "  ";
    }
    std::cout << std::endl;*/
    if(result.size() >0){
        std::shuffle(result.begin(), result.end(), *g);
        return result[0];
    }
    else{
        return NULL;
    }
}

Position::~Position(){

};