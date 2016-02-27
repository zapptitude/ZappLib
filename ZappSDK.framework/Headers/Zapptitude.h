//  Copyright (c) 2015 Zapptitude. All rights reserved.

#import <Foundation/Foundation.h>
/*!
  @class Zapptitude
  @abstract The Zapptitude class gathers the necessary methods to log users'
  activity in an app for the purpose of user's skill analysis and reporting.
  @discussion All the methods have been defined as class methods for ease of
  use, but a singleton class is used internally.
 
  No need to initialized the class, it is initialized at the first call of any
  method.
 
  Call [Zapptitude requestZid] early in your app, when an appropriate view
  is visible. This opens a dialog on top of the current view that gives the user
  the opportunity to provide, confirm, or change identity.
 
  Then, for each task, call
 
  [Zapptitude logBeginTask:@"myTaskX" in:@"myContestY"]
 
  whenever the task is presented to the user, and when a solution of proposed 
  call the appropriate
 
  [Zapptitude logSolve*Task:@"myTaskX" in:@"myContextY" about:@"3rd grade math" ...]
 
  depending on the nature of the task's answer: binary, integer, float, multiple
  choice, or graded.
  @updated 2015-05-31
 */
@interface Zapptitude : NSObject

/*!
  @brief Opens up a dialog on top of the current view, requesting
  the user for a Zapptitude id.
  @discussion If there is no known current user provided Zapptitude id, the
  user can either provide an id, or ignore the request and stay anonymous.
  If a user provided Zapptitude id already exists, the user is welcomed back
  and can either keep the same id (confirm his/her identity), change the id
  (change his/her identity), or clear the id (become anonymous).
 
  As part of the dialog, there is access to a brief description of the
  purpose of Zapptitude as well as a statement about data privacy.
 
  If the method is not called before a call to a logging method, the
  Zapptitude id used in the log is the last used Zapptitude id on the device,
  or anonymous if no known Zapptitude id is found.
 */
+ (void)requestZid;

/*!
  @brief Sets the Zapptitude id.
  @discussion It can be used instead of the requestZid method to set the
  Zapptitude id, whenever this id is determined in another way.
 
  An anonymous Zapptitude id is effectively a random id used to keep track
  of the activity of an anonymous user. Calling setZid with a nil or empty
  zid is equivalent to setting the Zapptitude id to anonymous. If the
  Zapptitude id is already anonymous, it is kept unchanged by a call to
  setZid with nil of and empty zid.
  @param zid NSString holding the value the Zapptitude id will be set to.
 */
+ (void)setZid:(NSString *)zid;

/*!
  @brief Returns the Zapptitude id, or nil if the user is anonymous.
  @return An NSString with the user provided Zapptitude id or nil if the user
  is anonymous.
 */
+ (NSString *)userProvidedZid;

/*!
  @brief Logs an event.
  @discussion This is used for regular app analytics. The event can be any
  string. It typically determines the kind of event as well as the location
  (stage) in the app the event occurs. The App bundle name and version are
  added to all logs, so the event dos not need to contain this information.
  @param event NSString containing the event.
 */
+ (void)logEvent:(NSString *)event;

/*!
  @brief Marks the beginning of the resolution of a task.
  @discussion The purpose of Zapptitude is to track the performance of a user
  on various tasks in the app, such as puzzles, quizzes, etc. Logging the
  beginning of each task allows Zapptitude to keep track of the time spent
  on each task, in addition to the correctness of the answer.
  @param task NSString uniquely identifying the problem to be solved.
  All logs with the same task are considered related to the same problem.
  It can be nil.
  @param context NSString holding any other additional information which does
  not define the task (e.g. some settings of the app) and which we might
  want to use to break down the reporting.
  It can be nil.
 */
+ (void)logBeginTask:(NSString *)task
                  in:(NSString *)context;

/*!
  @brief Marks the resolution of a binary task.
  @discussion A binary task has two possible outcomes.
 
  If logBeginTask is called before a logSolveBinaryTask with the same task
  and same context, the interval between the two calls is registered as the
  time to solve the task.
  @param task NSString uniquely identifying the problem being solved.
  @param context NSString holding any other additional information which does
  not define the task.
  @param topics NSString defining the topic, or topics, of the task. It is a
  comma separated list of topics (e.g. '3.NF,3rd grade math'). Guidelines for
  these topics are found on zapptitude.com.
  @param expected bool denoting the correct answer to the task.
  @param actual bool denoting the answer provided by the user.
 */
+ (void)logSolveBinaryTask:(NSString *)task
                        in:(NSString *)context
                     about:(NSString *)topics
                  expected:(BOOL)expected
                    actual:(BOOL)actual;

/*!
  @brief Marks the resolution of a task with numerical answers.
  @discussion
  If logBeginTask is called before logSolveIntTask with the same task
  and same context, the interval between the two calls is registered as the
  time to solve the task.
  @param task NSString uniquely identifying the problem being solved.
  @param context NSString holding any other additional information which does
  not define the task.
  @param topics NSString defining the topic, or topics, of the task. It is a
  comma separated list of topics (e.g. '3.NF,3rd grade math'). Guidelines for
  these topics are found on zapptitude.com.
  @param expected int denoting the correct answer to the task.
  @param actual int denoting the answer provided by the user. The numerical
  difference abs(expected - actual) measures the inaccuracy of the answer.
 */
+ (void)logSolveIntTask:(NSString *)task
                     in:(NSString *)context
                  about:(NSString *)topics
               expected:(int)expected
                 actual:(int)actual;

/*!
  @brief Marks the resolution of a task with numerical answers.
  @discussion
  If logBeginTask is called before logSolveFloatTask with the same task
  and same context, the interval between the two calls is registered as the
  time to solve the task.
  @param task NSString uniquely identifying the problem being solved.
  @param context NSString holding any other additional information which does
  not define the task.
  @param topics NSString defining the topic, or topics, of the task. It is a
  comma separated list of topics (e.g. '3.NF,3rd grade math'). Guidelines for
  these topics are found on zapptitude.com.
  @param expected float denoting the correct answer to the task.
  @param actual float denoting the answer provided by the user. The numerical
  difference abs(expected - actual) measures the inaccuracy of the answer.
 */
+ (void)logSolveFloatTask:(NSString *)task
                       in:(NSString *)context
                    about:(NSString *)topics
                 expected:(float)expected
                   actual:(float)actual;

/*!
  @brief Marks the resolution of a multiple choice task.
  @discussion A multiple choice task has a small number of possible
  unordered outcomes (e.g. {'A', 'B', 'C', 'D'}, where no order is
  considered).
 
  If logBeginTask is called before logSolveMCTask with the same task
  and same context, the interval between the two calls is registered as the
  time to solve the task.
  @param task NSString uniquely identifying the problem being solved.
  @param context NSString holding any other additional information which does
  not define the task.
  @param topics NSString defining the topic, or topics, of the task. It is a
  comma separated list of topics (e.g. '3.NF,3rd grade math'). Guidelines for
  these topics are found on zapptitude.com.
  @param expected char denoting the correct answer to the task.
  @param actual char denoting the answer provided by the user.
  @param choices int denoting the total number of possible outcomes.
 */
+ (void)logSolveMCTask:(NSString *)task
                    in:(NSString *)context
                 about:(NSString *)topics
              expected:(char)expected
                actual:(char)actual
                 among:(int)choices;

/*!
  @brief Marks the resolution of a task with gradual answers.
  @discussion A task with gradual answers has a small number of possible
  ordered outcomes (e.g. 'low', 'medium', 'high').
 
  If logBeginTask is called before logSolveGradTask with the same task
  and same context, the interval between the two calls is registered as the
  time to solve the task.
  @param task NSString uniquely identifying the problem being solved.
  @param context NSString holding any other additional information which does
  not define the task.
  @param topics NSString defining the topic, or topics, of the task. It is a
  comma separated list of topics (e.g. '3.NF,3rd grade math'). Guidelines for
  these topics are found on zapptitude.com.
  @param expected int denoting the correct answer to the task, converted in
  a packed integer range.
  @param actual int denoting the answer provided by the user, converted in the
  same packed integer range as 'expected'. The numerical difference
  abs(expected - actual) measures the inaccuracy of the answer and is at
  most grades - 1.
  @param grades int denoting the total number of possible outcomes.
 */
+ (void)logSolveGradTask:(NSString *)task
                      in:(NSString *)context
                   about:(NSString *)topics
                expected:(int)expected
                  actual:(int)actual
                   among:(int)grades;

@end
