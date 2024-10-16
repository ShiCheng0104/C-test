#ifndef E820C823_C431_4963_AAC8_6F3142379364
#define E820C823_C431_4963_AAC8_6F3142379364
#pragma once
#include <string>
namespace adas
{
    // 汽车姿态
    struct Pose
    {
        int x;
        int y;
        char heading;
    };

    class Executor
    {
    public:
        static Executor *NewExecutor(const Pose &pose = {0, 0, 'N'}) noexcept;

    public:
        // 默认构造函数
        Executor(void) = default;
        virtual ~Executor(void) = default;
        Executor(const Executor &) = delete;
        Executor &operator-(const Executor &) = delete;

    public:
        // 查询当前汽车姿态，纯虚函数，留给子类具体实现
        virtual Pose Query(void) const noexcept = 0;
        virtual void Execute(const std::string &commands) noexcept=0;
        
    };
}

#endif /* E820C823_C431_4963_AAC8_6F3142379364 */
