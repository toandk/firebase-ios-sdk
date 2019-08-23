/*
 * Copyright 2019 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>

#import "FIRAuth.h"
#import "FIRMultiFactorAssertion.h"
#import "FIRMultiFactorInfo.h"
#import "FIRMultiFactorSession.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^FIRMultiFactorSessionCallback)(FIRMultiFactorSession *_Nullable, NSError *_Nullable);

extern NSString *const _Nonnull FIRPhoneMultiFactorID NS_SWIFT_NAME(PhoneMultiFactorID);

NS_SWIFT_NAME(MultiFactor)
@interface FIRMultiFactor : NSObject

@property(nonatomic, readonly) NSArray<FIRMultiFactorInfo *> *enrolledFactors;

- (void)getSessionWithCompletion:(nullable FIRMultiFactorSessionCallback)completion;

- (void)enrollWithAssertion:(FIRMultiFactorAssertion*)assertion
                displayName:(nullable NSString *)displayName
                 completion:(nullable FIRAuthVoidErrorCallback)completion;

- (void)unenrollWithInfo:(FIRMultiFactorInfo *)factorInfo
              completion:(nullable FIRAuthVoidErrorCallback)completion;

- (void)unenrollWithFactorUID:(NSString *)factorUID
                   completion:(nullable FIRAuthVoidErrorCallback)completion;

@end

NS_ASSUME_NONNULL_END

