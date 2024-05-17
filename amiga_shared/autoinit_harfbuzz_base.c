/*
 * AutoInit stub for harfbuzz
 *
 * Copyright (c) 2012 Sebastian Bauer.
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of Keith Packard not be used in
 * advertising or publicity pertaining to distribution of the software without
 * specific, written prior permission.  Keith Packard makes no
 * representations about the suitability of this software for any purpose.  It
 * is provided "as is" without express or implied warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS
 * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS, IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING
 * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 */

#include <interfaces/harfbuzz.h>
#include <proto/exec.h>
#include <assert.h>

/****************************************************************************/

struct HarfbuzzLibrary *HarfbuzzBase = NULL;
static struct HarfbuzzLibrary *__HarfbuzzBase;

/****************************************************************************/

void harfbuzz_base_constructor(void)
{
    if (HarfbuzzBase != NULL)
    {
        return; /* Someone was quicker, e.g. an interface constructor */
    }
    __HarfbuzzBase = HarfbuzzBase = (struct HarfbuzzLibrary *)IExec->OpenLibrary("harfbuzz.library", 54L);
    assert(HarfbuzzBase != NULL);
}
__attribute__((section(".ctors.zzzz"))) static void (*harfbuzz_base_constructor_ptr)(void) USED = harfbuzz_base_constructor;

/****************************************************************************/

void harfbuzz_base_destructor(void)
{
    if (__HarfbuzzBase)
    {
        IExec->CloseLibrary((struct Library *)__HarfbuzzBase);
    }
}
__attribute__((section(".dtors.zzzz"))) static void (*harfbuzz_base_destructor_ptr)(void) USED = harfbuzz_base_destructor;

/****************************************************************************/
