"""
In a file called shirtificate.py, implement a program that:
- prompts the user for their name and outputs, using fpdf2, a CS50 shirtificate in a file called shirtificate.pdf similar to this one for John Harvard, with these specifications:

- The orientation of the PDF should be Portrait.
- The format of the PDF should be A4, which is 210mm wide by 297mm tall.
- The top of the PDF should “CS50 Shirtificate” as text, centered horizontally.
- The shirt’s image should be centered horizontally.
- The user’s name should be on top of the shirt, in white text.
- All other details we leave to you. You’re even welcome to add borders, colors, and lines. Your shirtificate needn’t match John Harvard’s precisely. And no need to wrap long names across multiple lines.

Before writing any code, do read through fpdf2’s tutorial to learn how to use it. Then skim fpdf2’s API (application programming interface) to see all of its functions and parameters therefor.

No need to submit any PDFs with your code. But, if you would like, you’re welcome (but not expected) to share a shirtificate with your name on it in any of CS50’s communities!
"""

from fpdf import FPDF


class PDF(FPDF):

    def header(self):
        # Rendering logo:
        self.image("shirtificate.png", 5, 60, 200)
        # Setting font: helvetica bold 15
        self.set_font("helvetica", "B", 40)
        # Moving cursor to the right:
        #self.cell(80)
        # Printing title:
        #self.cell(30, 10, "Title", border=1, align="C")
        self.cell(0, 40, txt="CS50 Shirtificate", align="C")
        #self.cell(-50, -50, txt="CS50 Shirtificate 100,100", align="C")
        # Performing a line break:
        self.ln(20)


    def set_auto_page_break(self, auto, margin=0):
        self.auto_page_break = auto
        self.b_margin = margin
        self.page_break_trigger = self.h - self.b_margin


    def footer(self):
        # Position cursor at 1.5 cm from bottom:
        self.set_y(-15)
        # Setting font: helvetica italic 8
        self.set_font("helvetica", "I", 8)
        # Printing page number:
        #self.cell(0, 10, f"Page {self.page_no()}/{{nb}}", align="C")

def main():

    name = input("Name: ")

    pdf = PDF()
    pdf.add_page()
    #pdf.image("shirtificate.png")
    pdf.set_text_color(255, 255, 255)
    pdf.set_font('courier', "B", size=26)

    #pdf.cell(-40, 10, txt="CS50 Shirtificate")
    pdf.cell(0 , 200, txt=f"{name} took cs50", align="C")

    pdf.output("shirtificate.pdf")

if __name__ == "__main__":
    main()


