//
//  AVPlayerOverlayVC.h
//
//  Created by Danilo Priore on 28/04/16.
//  Copyright © 2016 Prioregroup.com. All rights reserved.
//
#define AVPlayerOverlayVCFullScreenNotification             @"AVPlayerOverlayVCFullScreen"
#define AVPlayerOverlayVCNormalScreenNotification           @"AVPlayerOverlayVCNormalScreen"
#define AVPlayerOverlayVCAirPlayInUseNotification           @"AVPlayerOverlayVCAirPlayInUse"
#define AVPlayerOverlayVCAirPlayBecomePresentNotification   @"AVPlayerOverlayVCAirPlayBecomePresent"
#define AVPlayerOverlayVCAirPlayResignPresentNotification   @"AVPlayerOverlayVCAirPlayResignPresent"

#define kAVPlayerOverlayVCAirPlayInUse  @"airPlayInUse"

@import UIKit;

@class AVPlayer;

typedef NS_ENUM(NSInteger, AVPlayerFullscreenAutorotaionMode)
{
    AVPlayerFullscreenAutorotationDefaultMode,
    AVPlayerFullscreenAutorotationLandscapeMode
};

IB_DESIGNABLE
@interface AVPlayerOverlayVC : UIViewController

@property (nonatomic, weak) IBOutlet UIView *playerBarView;
@property (nonatomic, weak) IBOutlet UIButton *playButton;
@property (nonatomic, weak) IBOutlet UIButton *playBigButton;
@property (nonatomic, weak) IBOutlet UIButton *volumeButton;
@property (nonatomic, weak) IBOutlet UIButton *fullscreenButton;
@property (nonatomic, weak) IBOutlet UIButton *airPlayButton;
@property (nonatomic, weak) IBOutlet UIButton *subtitlesButton;
@property (nonatomic, weak) IBOutlet UISlider *videoSlider;
@property (nonatomic, weak) IBOutlet UISlider *volumeSlider;
@property (nonatomic, weak) IBOutlet UILabel *subtitlesLabel;
@property (nonatomic, weak) IBOutlet UILabel *currentTimeLabel;
@property (nonatomic, weak) IBOutlet UILabel *durationTimeLabel;

@property (nonatomic, weak) AVPlayer *player;

@property (nonatomic, assign) IBInspectable NSTimeInterval playBarAutoideInterval;
@property (nonatomic, assign) IBInspectable AVPlayerFullscreenAutorotaionMode autorotationMode;

@property (nonatomic, assign, readonly) BOOL isFullscreen;
@property (nonatomic, assign, readonly) BOOL isAirplayInUse;
@property (nonatomic, assign, readonly) BOOL isAirplayPresent;

@property (nonatomic, strong, readonly) NSString *airPlayPlayerName;

- (void)updateProgressBar;

- (void)autoHidePlayerBar;
- (void)hidePlayerBar;
- (void)showPlayerBar;

- (void)didTapGesture:(id)sender;
- (void)didDoubleTapGesture:(id)sender;
- (void)didPinchGesture:(id)sender;
- (void)didPlayButtonSelected:(id)sender;
- (void)didVolumeButtonSelected:(id)sender;
- (void)didFullscreenButtonSelected:(id)sender;
- (void)didSubtitlesButtonSelected:(id)sender;

- (void)didVolumeSliderValueChanged:(id)sender;

- (void)didVideoSliderTouchUp:(id)sender;
- (void)didVideoSliderTouchDown:(id)sender;
- (void)videoSliderEnabled:(BOOL)enabled;

- (void)willFullScreenModeFromParentViewController:(UIViewController*)parent;
- (void)didFullScreenModeFromParentViewController:(UIViewController*)parent;
- (void)willNormalScreenModeToParentViewController:(UIViewController*)parent;
- (void)didNormalScreenModeToParentViewController:(UIViewController*)parent;

- (void)showSubtitles;
- (void)hideSubtitles;
- (void)loadSubtitlesWithURL:(NSURL*)url;

- (NSAttributedString*)attributedSubtitle:(id)subtitle;

- (void)setupAirPlay;
- (void)deallocAirplay;
- (void)airPlayRouteChange:(NSNotification*)note;
- (BOOL)checkAirPlayIsRunning;
- (void)airPlayChangeInUseState:(BOOL)isInUse;

- (void)airplayBecomePresent;
- (void)airplayResignPresent;

- (void)forceDeviceOrientation:(UIInterfaceOrientation)orientation;
- (void)deviceOrientationDidChange:(NSNotification *)notification;

@end
