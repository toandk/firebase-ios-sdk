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

#import "FIRAuthBackend.h"

#import "FIRStartMfaEnrollmentRequest.h"
#import "FIRStartMfaEnrollmentResponse.h"
#import "FIRFinalizeMfaEnrollmentRequest.h"
#import "FIRFinalizeMfaEnrollmentResponse.h"
#import "FIRStartMfaSignInRequest.h"
#import "FIRStartMfaSignInResponse.h"
#import "FIRFinalizeMfaSignInRequest.h"
#import "FIRFinalizeMfaSignInResponse.h"
#import "FIRWithdrawMfaRequest.h"
#import "FIRWithdrawMfaResponse.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^FIRStartMfaEnrollmentResponseCallback)
(FIRStartMfaEnrollmentResponse *_Nullable response, NSError *_Nullable error);

typedef void (^FIRFinalizeMfaEnrollmentResponseCallback)
(FIRFinalizeMfaEnrollmentResponse *_Nullable response, NSError *_Nullable error);

typedef void (^FIRStartMfaSignInResponseCallback)
(FIRStartMfaSignInResponse *_Nullable response, NSError *_Nullable error);

typedef void (^FIRFinalizeMfaSignInResponseCallback)
(FIRFinalizeMfaSignInResponse *_Nullable response, NSError *_Nullable error);

typedef void (^FIRWithdrawMfaResponseCallback)
(FIRWithdrawMfaResponse *_Nullable response, NSError *_Nullable error);

@interface FIRAuthBackend (MultiFactor)

+ (void)startMultiFactorEnrollment:(FIRStartMfaEnrollmentRequest *)request
                          callback:(FIRStartMfaEnrollmentResponseCallback)callback;

+ (void)finalizeMultiFactorEnrollment:(FIRFinalizeMfaEnrollmentRequest *)request
                             callback:(FIRFinalizeMfaEnrollmentResponseCallback)callback;

+ (void)startMultiFactorSignIn:(FIRStartMfaSignInRequest *)request
                      callback:(FIRStartMfaSignInResponseCallback)callback;

+ (void)finalizeMultiFactorSignIn:(FIRFinalizeMfaSignInRequest *)request
                         callback:(FIRFinalizeMfaSignInResponseCallback)callback;

+ (void)withdrawMultiFactor:(FIRWithdrawMfaRequest *)request
                   callback:(FIRWithdrawMfaResponseCallback)callback;

@end

NS_ASSUME_NONNULL_END
