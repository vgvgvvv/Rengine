//
// Created by 董宸 on 11/12/2017.
//

#ifndef PROJECT_GAMEUPDATER_H
#define PROJECT_GAMEUPDATER_H

namespace Core{
    class GameUpdater {
    public:
        /**
         * 进行初始化
         */
        void Init();
        /**
         * 进行更新
         * @param delayTime
         */
        void Update(float delayTime);
        /**
         * 卸载
         */
        void UnInit();
    };
}



#endif //PROJECT_GAMEUPDATER_H
