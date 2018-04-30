//
// Created by 董宸 on 19/01/2018.
//

#ifndef LEARNINGOPENGL_IREUSABLE_HPP
#define LEARNINGOPENGL_IREUSABLE_HPP

namespace ReEngine{
    template <typename... TArgs>
    class IReusable{
    public:
        virtual void OnGet(TArgs... params) = 0;
        virtual void OnReturn() = 0;
    };
}


#endif //LEARNINGOPENGL_IREUSABLE_HPP
