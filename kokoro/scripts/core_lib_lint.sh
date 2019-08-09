#!/bin/bash

# Copyright 2019 Google
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#      http://www.apache.org/licenses/LICENSE-2.0
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

ROOT_DIR=$KOKORO_ARTIFACTS_DIR/github/firebase-ios-sdk
# DEVELOPER_DIR=/Applications/Xcode_10.1.app
sudo xcode-select -s /Applications/Xcode_10.1.app

cd $ROOT_DIR

echo $(pwd)

bundle install

./scripts/pod_lib_lint.rb GoogleUtilities.podspec --verbose