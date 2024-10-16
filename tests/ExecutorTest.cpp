#include <gtest/gtest.h> 
#include <memory> 
#include <tuple> 
#include "Executor.hpp" 
using namespace adas;
namespace adas
{
    bool operator==(const Pose &lhs, const Pose &rhs){
        return std::tie(lhs.x, lhs.y, lhs.heading)== std::tie(rhs.x, rhs.y, rhs.heading); 
    }
    TEST(ExecutorTest, should_return_init_pose_when_vithout_command){
        //given给定测试条件
        //测试条件就是调用Executor的静态方法NewExecutor返回一个指向Executor对象的智能指executor， 这样我们就不需要去delete了
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0,0,'E'}));//给了初始姿势
        //when


        //then
        const Pose target({0,0,'E'});//构造一个姿势对象target，其内容为0,0,'E'
        //既然构造Executor对象时的初始姿势是0,0,'E',那么executor->Query()返回的Executor对象的姿势必须等于target
        //所以这里用了断言:executor->QueryO返回的Executor对象的姿势必须等于target，否则澳试失败，说明Executor的实现有问题
        ASSERT_EQ(target,executor->Query());
    }
    TEST (ExecutorTest, should_return_detault_pose_when_without_init_and_command) {
        std::unique_ptr<Executor> executor(Executor::NewExecutor());//没有给初始咨势
        //when


        //then
        const Pose target({0, 0, 'N' });
        ASSERT_EQ(target, executor->Query()) ;
    }

    TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
    {
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 给了初始姿势
        // when

        // then
        executor->Execute("M");
        const Pose target({1, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }

} // namespace adas




    