#include "main.h"
#include <iostream>

TEST(OutcursesPanelReel, InitLinear) {
  if(getenv("TERM") == nullptr){
    GTEST_SKIP();
  }
  panelreel_options p = { };
  ASSERT_EQ(0, init_outcurses(true));
  struct panelreel* pr = create_panelreel(&p);
  ASSERT_NE(nullptr, pr);
  ASSERT_EQ(0, stop_outcurses(true));
}

TEST(OutcursesPanelReel, InitLinearInfinite) {
  if(getenv("TERM") == nullptr){
    GTEST_SKIP();
  }
  panelreel_options p = {
    .infinitescroll = true,
  };
  ASSERT_EQ(0, init_outcurses(true));
  struct panelreel* pr = create_panelreel(&p);
  ASSERT_NE(nullptr, pr);
  ASSERT_EQ(0, stop_outcurses(true));
}

TEST(OutcursesPanelReel, InitCircular) {
  if(getenv("TERM") == nullptr){
    GTEST_SKIP();
  }
  panelreel_options p = {
    .infinitescroll = true,
    .circular = true,
  };
  ASSERT_EQ(0, init_outcurses(true));
  struct panelreel* pr = create_panelreel(&p);
  ASSERT_NE(nullptr, pr);
  ASSERT_EQ(0, destroy_panelreel(pr));
  ASSERT_EQ(0, stop_outcurses(true));
}

// circular is not allowed to be true when infinitescroll is false
TEST(OutcursesPanelReel, FiniteCircleRejected) {
  if(getenv("TERM") == nullptr){
    GTEST_SKIP();
  }
  panelreel_options p = {
    .infinitescroll = false,
    .circular = true,
  };
  ASSERT_EQ(0, init_outcurses(true));
  struct panelreel* pr = create_panelreel(&p);
  ASSERT_EQ(nullptr, pr);
  ASSERT_EQ(0, stop_outcurses(true));
}
