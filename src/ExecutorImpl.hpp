#ifndef F3341538_5DAA_4ED2_A163_70137A4997ED
#define F3341538_5DAA_4ED2_A163_70137A4997ED
#include<Executor.hpp>
#include<string>

namespace adas
{
    class ExecutorImpl:public Executor{
    public:
        explicit ExecutorImpl(const Pose &pose ) noexcept;
        ~ExecutorImpl() noexcept=default;
        ExecutorImpl(const ExecutorImpl&)=delete;
        ExecutorImpl &operator=(const ExecutorImpl&)=delete;
    public:
        Pose Query(void) const noexcept override;
        void Execute(const std::string &commands) noexcept override;
    private:
        Pose pose;
    };
} // namespace adas


#endif /* F3341538_5DAA_4ED2_A163_70137A4997ED */
