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

struct HarfbuzzIFace *IHarfbuzz = NULL;
static struct HarfbuzzLibrary * __HarfbuzzBase;
static struct HarfbuzzIFace * __IHarfbuzz;

/****************************************************************************/

extern struct HarfbuzzLibrary * HarfbuzzBase;

/****************************************************************************/

void harfbuzz_main_constructor(void)
{
    if (HarfbuzzBase == NULL) /* Library base is NULL, we need to open it */
    {
        /* We were called before the base constructor.
         * This means we will be called _after_ the base destructor.
         * So we cant drop the interface _after_ closing the last library base,
         * we just open the library here which ensures that.
         */
        __HarfbuzzBase = HarfbuzzBase = (struct HarfbuzzLibrary *)IExec->OpenLibrary("harfbuzz.library", 54L);
        assert(HarfbuzzBase != NULL);
    }

    __IHarfbuzz = IHarfbuzz = (struct HarfbuzzIFace *)IExec->GetInterface((struct Library *)HarfbuzzBase, "main", 1, NULL);
    assert(IHarfbuzz != NULL);
}
__attribute__((section(".ctors.zzzy"))) static void
(*harfbuzz_main_constructor_ptr)(void) USED = harfbuzz_main_constructor;

/****************************************************************************/

void harfbuzz_main_destructor(void)
{
    if (__IHarfbuzz)
    {
        IExec->DropInterface ((struct Interface *)__IHarfbuzz);
    }
    if (__HarfbuzzBase)
    {
        IExec->CloseLibrary((struct Library *)__HarfbuzzBase);
    }
}
__attribute__((section(".dtors.zzzy"))) static void
(*harfbuzz_main_destructor_ptr)(void) USED = harfbuzz_main_destructor;

/****************************************************************************/
