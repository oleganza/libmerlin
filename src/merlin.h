#ifndef MERLIN_H
#define MERLIN_H
#define __STDC_WANT_LIB_EXT1__ 1
#include <stdint.h>
#include <stdlib.h>

/* XXX can these be made opaque without malloc? */

typedef struct merlin_strobe128_ {
  /* XXX endianness */
  union {
    uint64_t state[25];
    uint8_t state_bytes[200];
  };
  uint8_t pos;
  uint8_t pos_begin;
  uint8_t cur_flags;
} merlin_strobe128;

typedef struct merlin_transcript_ {
  merlin_strobe128 sctx;
} merlin_transcript;

void merlin_transcript_init(merlin_transcript* mctx,
			    const uint8_t* label,
			    size_t label_len);

void merlin_transcript_commit_bytes(merlin_transcript* mctx,
                                    const uint8_t* label,
                                    size_t label_len,
                                    const uint8_t* data,
                                    size_t data_len);

void merlin_transcript_challenge_bytes(merlin_transcript* mctx,
                                       const uint8_t* label,
                                       size_t label_len,
                                       uint8_t* buffer,
                                       size_t buffer_len);

#endif
