//
//  PrinterManager.hpp
//  question2
//
//  Created by Seungyong Lee on 2017. 4. 16..
//  Copyright © 2017년 Seungyong Lee. All rights reserved.
//

#ifndef PrinterManager_hpp
#define PrinterManager_hpp

class Printer
{
private:
    std::string savedStr;
    
public:
    void SetString(std::string str);
    void ShowString();
};

#endif /* PrinterManager_hpp */
