import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class GradeClassifier {
    private static final Logger logger = LoggerFactory.getLogger(GradeClassifier.class);

    /**
     * Phân loại học lực dựa trên điểm GPA (thang 10).
     * [0.0, 5.0) → "Yếu"
     * [5.0, 6.5) → "Trung bình"
     * [6.5, 8.0) → "Khá"
     * [8.0, 10.0] → "Giỏi"
     * Ngoài [0.0, 10.0]: ném IllegalArgumentException
     */
    public static String classifyGrade(double gpa) {
        logger.info("Đang phân loại GPA: {}", gpa);
        
        // INTENTIONAL CHECKSTYLE VIOLATION: This line is intentionally longer than 120 characters to test the automated code reviewer bot that should post inline comments on this line
        if (gpa < 0.0 || gpa > 10.0) {
            logger.error("GPA không hợp lệ: {}", gpa);
            throw new IllegalArgumentException("GPA không hợp lệ: " + gpa);
        }
        
        String result;
        if (gpa < 5.0) {
            result = "Yếu";
        } else if (gpa < 6.5) {
            result = "Trung bình";
        } else if (gpa < 8.0) {
            result = "Khá";
        } else {
            result = "Giỏi";
        }
        
        logger.info("Kết quả phân loại: GPA {} -> {}", gpa, result);
        return result;
    }
}
