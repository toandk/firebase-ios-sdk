Pod::Spec.new do |s|
  s.name             = 'FirebaseDynamicLinks'
  s.version          = '4.0.7'
  s.summary          = 'Firebase DynamicLinks for iOS'

  s.description      = <<-DESC
Firebase Dynamic Links are deep links that enhance user experience and increase engagement by retaining context post-install, across platforms.
                       DESC

  s.homepage         = 'https://firebase.google.com'
  s.license          = { :type => 'Apache', :file => 'LICENSE' }
  s.authors          = 'Google, Inc.'

  s.source           = {
    :git => 'https://github.com/toandk/firebase-ios-sdk.git',
    :branch => 'release-6.17.0',
    :tag => 'DynamicLinks-' + s.version.to_s
  }
  s.social_media_url = 'https://twitter.com/Firebase'
  s.ios.deployment_target = '8.0'

  s.cocoapods_version = '>= 1.4.0'
  s.static_framework = true
  s.prefix_header_file = false

  s.source_files = 'FirebaseDynamicLinks/Sources/**/*.[mh]'
  s.public_header_files = 'FirebaseDynamicLinks/Sources/Public/*.h'
  s.frameworks = 'AssetsLibrary', 'MessageUI', 'QuartzCore'
  s.weak_framework = 'WebKit'
  s.dependency 'FirebaseCore', '~> 6.2'
  s.dependency 'FirebaseAnalyticsInterop', '~> 1.3'

  s.pod_target_xcconfig = {
    'GCC_C_LANGUAGE_STANDARD' => 'c99',
    'GCC_PREPROCESSOR_DEFINITIONS' => 'FIRDynamicLinks_VERSION=' + s.version.to_s +
                                      ' FIRDynamicLinks3P GIN_SCION_LOGGING',
    'HEADER_SEARCH_PATHS' => '"${PODS_TARGET_SRCROOT}"'
  }

  s.test_spec 'unit' do |unit_tests|
    unit_tests.source_files = 'FirebaseDynamicLinks/Tests/Unit/*.[mh]'
    unit_tests.requires_app_host = true
    unit_tests.resources = 'FirebaseDynamicLinks/Tests/Unit/GoogleService-Info.plist',
                           # Supply plist for custom domain testing.
                           'FirebaseDynamicLinks/Tests/Unit/DL-Info.plist'
    unit_tests.dependency 'OCMock'
    unit_tests.dependency 'GoogleUtilities/MethodSwizzler', '~> 6.2'
    unit_tests.dependency 'GoogleUtilities/SwizzlerTestHelpers', '~> 6.2'
  end
end
